#include "entity.h"
#include "assets.h"

void Entity::setFaceRight(const bool &face){
    faceRight = face;
}

int Entity::setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{ // whereAm
    if (platforms.size() < 2)
        return current_stage = 0;
    sf::FloatRect bound = this->getGlobalBounds();
    for (std::size_t i = 0; i + 1 < platforms.size(); ++i)
    {
        const float top = platforms[i]->getGlobalBounds().top;
        const float next_top = platforms[i + 1]->getGlobalBounds().top;
        if (top < bound.top && bound.top < next_top)
            return current_stage = static_cast<int>(i + 1);
    }
    return static_cast<int>(platforms.size() - 1);
}

void Entity::updateGravity(const float &dt)
{
    velocity.y += gravity * dt;
    if(bounce)
    {
        velocity.y -= 1 / 5.f * gravity * dt; // bouncing coin
    }
}

void Entity::updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if (platforms.empty())
        return;
    const int last = static_cast<int>(platforms.size()) - 1;
    if (next_stage < 0)
        next_stage = 0;
    else if (next_stage > last)
        next_stage = last;

    grounded = false;
    sf::FloatRect playerBounds = this->getGlobalBounds();
    sf::FloatRect playerBoundsNext = this->getGlobalBounds();
    playerBoundsNext.left = getPosition().x + velocity.x * dt;
    playerBoundsNext.top = getPosition().y + velocity.y * dt;
    current_stage = setBounds(platforms);
    sf::FloatRect next_stagePlatformBounds = platforms[next_stage]->getGlobalBounds();
    if (bounce)
    {
        next_stagePlatformBounds = platforms[current_stage]->getGlobalBounds();
    }
    if (next_stagePlatformBounds.intersects(playerBoundsNext))
    { //bottom
        if (playerBounds.top < next_stagePlatformBounds.top && playerBounds.top + playerBounds.height < next_stagePlatformBounds.top + next_stagePlatformBounds.height && playerBounds.left < next_stagePlatformBounds.left + next_stagePlatformBounds.width && playerBounds.left + playerBounds.width > next_stagePlatformBounds.left)
        {
            if (!bounce)
            {
                velocity.y = 0;
            }
            else
            {
                velocity.y = -std::abs(velocity.y);
                velocity.y += 3;
            }
            switcher = 0;
            grounded = true;
            stage_down = true;
            this->setPosition(playerBounds.left, next_stagePlatformBounds.top - playerBounds.height);
        }
    }
    if (playerBounds.top + playerBounds.height > height_screen)
    { //zapobiega spadaniu
        this->setPosition(playerBounds.left, next_stagePlatformBounds.top - playerBounds.height);
    }
    if ((playerBounds.left + playerBounds.width) < 5)
    { //przejsce w lewo
        this->setPosition(width_screen - playerBounds.left - playerBounds.width, next_stagePlatformBounds.top - playerBounds.height);
    }
    if ((playerBounds.left) > width_screen)
    { //przejscie w prawo
        this->setPosition(-(50) / 2.0, next_stagePlatformBounds.top - playerBounds.height);
    }
    this->updateGravity(dt);
    this->move(velocity * dt);
}

Entity::Entity(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
               const int &len_idle, const int &len_move, const int &len_jump)
    : Animation(frame, framerate)
{
    this->setScale(6, 6);
    this->setPosition(pos);
    value = 0;
    textures_.reserve(4);
    frames_.reserve(4);
    const sf::Texture &idle_texture = cachedTexture("Texture/engineer character/engineer-idle.png");
    frames_.push_back(addAnimation(frame, len_idle));
    textures_.push_back(&idle_texture);
    const sf::Texture &run_texture = cachedTexture("Texture/engineer character/engineer-run.png");
    frames_.push_back(addAnimation(frame, len_move));
    textures_.push_back(&run_texture);
    const sf::Texture &jump_texture = cachedTexture("Texture/engineer character/engineer-jump.png");
    frames_.push_back(addAnimation(frame, len_jump));
    textures_.push_back(&jump_texture);
    //animacja otrzymania obrazen
    frames_.push_back(addAnimation(sf::IntRect(frame.left,frame.top,frame.width,frame.height - 5), len_idle));
    textures_.push_back(&idle_texture);
    this->setTexture(*textures_[0]);
}

Entity::Entity(const std::vector<std::unique_ptr<sf::Sprite> > &platforms, const int &x,
               const sf::IntRect &frame, const float &framerate, const float &lenght)
    : Animation(frame, framerate, lenght)
{
    this->setScale(4, 4);
    const char *file = "Texture/MonedaD.png";
    value = 100;
    if (x < 9)
    {
        file = "Texture/MonedaR.png";
        value = 25;
    }
    else if (x <= 13)
    {
        file = "Texture/MonedaP.png";
        value = 50;
    }
    const sf::Texture &texture = cachedTexture(file);
    textures_.push_back(&texture);
    this->setTexture(texture);
    this->setPosition(sf::Vector2f(static_cast<float>(std::rand() % 1820), static_cast<float>(std::rand() % 1030)));
    current_stage = setBounds(platforms);
    next_stage = current_stage;
    for (auto &pl : platforms)
    {
        int guard = 0;
        while (guard < 32 && pl->getGlobalBounds().intersects(this->getGlobalBounds()))
        {
            this->setPosition(sf::Vector2f(static_cast<float>(std::rand() % 1820), static_cast<float>(std::rand() % 1030)));
            ++guard;
        }
    }
}
