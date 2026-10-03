#include "objectmanager.h"
#include "assets.h"

#include <iostream>

void ObjectManager::add(const int &m, const int &n, std::unique_ptr<Object> block_)
{
    board_.insert(make_pair(m, std::map<int, std::unique_ptr<Object>>()));
    board_[m].insert(make_pair(n, std::move(block_)));
}

void ObjectManager::Reverse(const int &m, const int &n, const Object::Color &color)
{
    int Intcolor = static_cast<int>(color);
    board_[m][n]->SetFill();
    board_[m][n]->Paint(color);
    bool reverse = false;
    if( board_[m][n]->getFill() == Object::Fill::full_full){
        for (int i = n; i < columns; i++)
        { // to left
            if (board_[m][i]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[m][i]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            else if ( i+1 != columns && board_[m][i + 1]->getIntColor() == Intcolor && reverse == false)
            {
                reverse = false;
                break;
            }
            if (board_[m][i]->getFill() == Object::Fill::full_full
                    && board_[m][i]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = n; k < i; k++)
                {
                    board_[m][k]->Paint(color);
                }
                break; //or continue?
            }

        }
        reverse = false;
        for (int i = n; i >= 0; i--)
        { // to right
            if (board_[m][i]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[m][i]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            else if (i > 0 && board_[m][i - 1]->getIntColor() == Intcolor && reverse == false)
            {
                reverse = false;
                break;
            }
            if (board_[m][i]->getFill() == Object::Fill::full_full
                    && board_[m][i]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = n; k > i; k--)
                {
                    board_[m][k]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m; i >= 0; i--)
        { // up
            if (board_[i][n]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][n]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][n]->getFill() == Object::Fill::full_full &&
                    board_[i][n]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m; k > i; k--)
                {
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m; i < rows; i++)
        { // down
            if (board_[i][n]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][n]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][n]->getFill() == Object::Fill::full_full &&
                    board_[i][n]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m; k < i; k++)
                {
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i < rows && j < columns; ++i, ++j)
        { // \ from r to l
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k < i && l < j; ++k, ++l)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i >= 0 && j >= 0; --i, --j)
        { // \ from l to r
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if (board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k > i && l > j; --k, --l)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i < rows && j >= 0; ++i, --j)
        { // / left to right
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k < i && l > j; ++k, --l)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i >= 0 && j < columns; --i, ++j)
        { // / left to right
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k > i && l < j; --k, ++l)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
    }
}

const std::map<int, std::map<int, std::unique_ptr<Object>>> &ObjectManager::getBoard() const
{
    return board_;
}

void ObjectManager::addScore(Hero &gracz, Hero &enemy){
    while(!end_game)
    {
        for (const auto &el : board_)
        {

            for (const auto &v : el.second)
            {
                if (v.second->getColor_Object() == gracz.getColor_Object())
                {
                    gracz.addScore(175);
                }
                if (v.second->getColor_Object() == enemy.getColor_Object() )
                {
                    enemy.addScore(175);
                }
            }
        }
        end_game = true;
    }
}

void ObjectManager::Paint(const sf::RenderWindow &window, const sf::Event &event)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    //std::cerr << "XY M : " << mouse_pos.x << " y : " << mouse_pos.y << std::endl;
    for (auto &bd : board_)
    {
        for (auto &bd_el : bd.second)
        {
            if (bd_el.second->getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    bd_el.second->Paint(Object::Color::Player);
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    bd_el.second->Paint(Object::Color::Enemy);
                }
            }
        }
    }
}

void ObjectManager::Paint(Hero &hero)
{
    const sf::FloatRect playerBounds = hero.getGlobalBounds();
    const float px = playerBounds.left + playerBounds.width * 0.5f;
    const float py = playerBounds.top + playerBounds.height - 10.f;
    for (auto &bd : board_)
    {
        const int m = bd.first;
        for (auto &bd_el : bd.second)
        {
            if (!bd_el.second->getGlobalBounds().contains(px, py))
                continue;
            if (hero.painting() && hero.can_paint()
                    && bd_el.second->getFill() != Object::Fill::full_full)
            {
                this->Reverse(m, bd_el.first, hero.getColor_Object());
                if (paint_sound_)
                    painting_effect.play();
                hero.addScore(25);
            }
            return;
        }
    }
}


bool ObjectManager::full_board()
{
    for (const auto &el : board_)
    {
        for (const auto &v : el.second)
        {
            if ( v.second->getFill() != Object::Fill::full_full )
            {
                return false;
            }
        }
    }
    return true;
}

void ObjectManager::draw()
{
    for (const auto &el : board_)
    {
        for (const auto &v : el.second)
        {
            if( v.second->is_visible()){

                window_->draw(*v.second);
            }
        }
    }
}

ObjectManager::ObjectManager(sf::RenderWindow *window) : window_(window)
{
    const sf::Texture &texture = cachedTexture("Texture/Dungeons Walls.png", true);
    for (int i = 0; i < columns; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            std::unique_ptr<Object> block_ = std::make_unique<Object>(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), texture);
            this->add(k, i, std::move(block_));
            y += 247;
        }
        x+= 7.25 * 32;
        y = 25.0 ;
    }
    const std::string painting = assetPath("Audio/painting.wav");
    if (!buffer.loadFromFile(painting))
        std::cerr << "Builder Panic: paint sound disabled (" << painting << ")\n";
    else
    {
        painting_effect.setBuffer(buffer);
        paint_sound_ = true;
    }
}
