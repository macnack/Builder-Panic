#include "smartenemy.h"
#include "objectmanager.h"

#include <cmath>
#include <cstdlib>

namespace {

float wrapDelta(float from, float to, float width)
{
    float d = to - from;
    if (d > width * 0.5f)
        d -= width;
    if (d < -width * 0.5f)
        d += width;
    return d;
}

int nearestFloor(float y, const std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{
    int best = 0;
    float best_d = 1.0e9f;
    for (int i = 0; i < static_cast<int>(platforms.size()); ++i)
    {
        const float top = platforms[static_cast<std::size_t>(i)]->getGlobalBounds().top;
        const float d = std::fabs(top - y);
        if (d < best_d)
        {
            best_d = d;
            best = i;
        }
    }
    return best;
}

Object *cellAt(const std::map<int, std::map<int, std::unique_ptr<Object>>> &board, int row, int col)
{
    const auto row_it = board.find(row);
    if (row_it == board.end())
        return nullptr;
    const auto col_it = row_it->second.find(col);
    if (col_it == row_it->second.end())
        return nullptr;
    return col_it->second.get();
}

// Bonus when finishing this cell would close a Reversi line on an opponent.
int captureBonus(const std::map<int, std::map<int, std::unique_ptr<Object>>> &board,
                 int row, int col, int mine, int opponent)
{
    const int dirs[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    int bonus = 0;
    for (int d = 0; d < 8; ++d)
    {
        bool saw_opponent = false;
        for (int step = 1; step < 8; ++step)
        {
            Object *cell = cellAt(board, row + dirs[d][0] * step, col + dirs[d][1] * step);
            if (!cell)
                break;
            const int color = cell->getIntColor();
            if (color == 0)
                break;
            if (color == opponent)
                saw_opponent = true;
            if (color == mine && cell->getFill() == Object::Fill::full_full && saw_opponent)
            {
                bonus += 40;
                break;
            }
            if (color == mine && !saw_opponent)
                break;
        }
    }
    return bonus;
}

} // namespace

SmartEnemy::SmartEnemy(const sf::Vector2f &pos)
    : Hero(pos, Object::Color::Enemy)
{
    last_x_ = pos.x;
}

void SmartEnemy::sense(Hero &player, const ObjectManager &walls)
{
    player_ = &player;
    walls_ = &walls;
}

void SmartEnemy::resetRound()
{
    Hero::resetRound();
    human_controlled_ = false;
    want_paint_ = false;
    want_jump_ = false;
    want_down_ = false;
    want_attack_ = false;
    patrol_dir_ = -1;
    steer_x_ = 0.f;
    decision_timer_ = 0.f;
    chase_timer_ = 0.f;
    stuck_timer_ = 0.f;
    last_x_ = this->getPosition().x;
}

bool SmartEnemy::painting()
{
    if (human_controlled_)
        return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
    return want_paint_;
}

bool SmartEnemy::read_human_keys() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::M)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::N);
}

void SmartEnemy::change_platform()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->down();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->jump();
}

void SmartEnemy::think(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, float dt)
{
    want_paint_ = false;
    want_jump_ = false;
    want_down_ = false;
    want_attack_ = false;
    steer_x_ = 0.f;

    const sf::FloatRect self = this->getGlobalBounds();
    const float self_x = self.left + self.width * 0.5f;

    float goal_x = self_x + static_cast<float>(patrol_dir_) * 400.f;
    int goal_stage = current_stage;
    bool seeking = false;
    bool chasing = false;

    const bool player_known = player_ != nullptr && walls_ != nullptr && !platforms.empty();
    float dx_player = 0.f;
    int player_stage = current_stage;
    bool player_painting = false;
    if (player_known)
    {
        const sf::FloatRect them = player_->getGlobalBounds();
        const float player_x = them.left + them.width * 0.5f;
        dx_player = wrapDelta(self_x, player_x, width_screen);
        player_stage = nearestFloor(them.top + them.height, platforms);
        player_painting = player_->painting();

        const auto &board = walls_->getBoard();
        const int mine = static_cast<int>(Object::Color::Enemy);
        bool found = false;
        int best_score = 0;
        float best_x = self_x;
        int best_stage = current_stage;
        for (const auto &row : board)
        {
            for (const auto &col : row.second)
            {
                Object &wall = *col.second;
                if (wall.getFill() == Object::Fill::full_full)
                    continue;
                const sf::FloatRect bounds = wall.getGlobalBounds();
                const float cx = bounds.left + bounds.width * 0.5f;
                const float cy = bounds.top + bounds.height * 0.5f;
                const int stage = nearestFloor(cy, platforms);
                int score = 30;
                if (wall.getColor_Object() == Object::Color::Enemy)
                    score = 60;
                else if (wall.getColor_Object() == Object::Color::Player)
                    score = 45;
                if (wall.getFill() == Object::Fill::full)
                    score += 25;
                else if (wall.getFill() == Object::Fill::two_thirds)
                    score += 12;
                if (stage == current_stage)
                    score += 35;
                else
                    score -= 15 * std::abs(stage - current_stage);
                score -= static_cast<int>(std::fabs(wrapDelta(self_x, cx, width_screen)) / 40.f);
                score += captureBonus(board, row.first, col.first, mine, -mine);
                if (player_painting && stage == player_stage
                        && std::fabs(wrapDelta(player_x, cx, width_screen)) < 120.f)
                    score += 70;
                if (!found || score > best_score)
                {
                    found = true;
                    best_score = score;
                    best_x = cx;
                    best_stage = stage;
                }
            }
        }
        if (found)
        {
            seeking = true;
            goal_x = best_x;
            goal_stage = best_stage;
        }

        const float adx = std::fabs(dx_player);
        const int stage_gap = std::abs(player_stage - current_stage);
        const bool same_floor = current_stage == player_stage;
        // Painting is the job. Chase only to interrupt a painter or to shove someone
        // who is already in melee, and don't orbit a player who is just standing there.
        const bool contest = player_painting && ((same_floor && adx < 700.f) || (stage_gap == 1 && adx < 320.f));
        const bool melee = same_floor && adx < 120.f;
        if (contest || melee)
            chase_timer_ += dt;
        else
            chase_timer_ = 0.f;
        const bool chase = contest || (melee && chase_timer_ < 1.2f);
        if (chase)
        {
            seeking = false;
            chasing = true;
            goal_x = player_x;
            goal_stage = player_stage;
            if (melee)
                want_attack_ = true;
        }
    }

    steer_x_ = wrapDelta(self_x, goal_x, width_screen);
    if (seeking && goal_stage == current_stage && std::fabs(steer_x_) < 48.f)
        want_paint_ = true;

    if (goal_stage < current_stage)
        want_jump_ = true;
    else if (goal_stage > current_stage)
        want_down_ = true;

    if (!seeking && !chasing)
    {
        decision_timer_ += dt;
        if (decision_timer_ > 2.2f)
        {
            patrol_dir_ = -patrol_dir_;
            decision_timer_ = 0.f;
            if (player_known && patrol_dir_ > 0 && current_stage > 1)
                want_jump_ = true;
            else if (player_known && current_stage < 4)
                want_down_ = true;
        }
        steer_x_ = static_cast<float>(patrol_dir_) * 400.f;
    }

    const float moved = std::fabs(this->getPosition().x - last_x_);
    if (!want_paint_ && std::fabs(steer_x_) > 40.f && moved < 0.75f)
        stuck_timer_ += dt;
    else
        stuck_timer_ = 0.f;
    last_x_ = this->getPosition().x;
    if (stuck_timer_ > 0.6f)
    {
        patrol_dir_ = -patrol_dir_;
        steer_x_ = static_cast<float>(patrol_dir_) * 400.f;
        want_paint_ = false;
        if (current_stage < 4)
        {
            want_down_ = true;
            want_jump_ = false;
        }
        else
        {
            want_jump_ = true;
            want_down_ = false;
        }
        stuck_timer_ = 0.f;
    }
}

void SmartEnemy::loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if (this->read_human_keys())
        human_controlled_ = true;

    this->change_platform_cooldown(dt);
    if (!this->stunned())
    {
        if (human_controlled_)
        {
            if (!this->painting())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    this->attack_move();
                this->change_platform();
            }
        }
        else
        {
            this->think(platforms, dt);
            if (want_paint_)
            {
                velocity.x = 0.f;
            }
            else
            {
                if (std::fabs(steer_x_) < 140.f)
                    velocity.x = steer_x_ * 3.f;
                else if (steer_x_ < 0.f)
                    this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
                else if (steer_x_ > 0.f)
                    this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
                if (want_attack_)
                    this->attack_move();
                if (want_down_)
                    this->down();
                else if (want_jump_)
                    this->jump();
            }
        }
        this->wall_painting(dt);
    }
    else
    {
        want_paint_ = false;
    }

    this->cooldown(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}
