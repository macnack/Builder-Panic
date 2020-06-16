#include "entity.h"

void Entity::setFaceRight(const bool &face){
    faceRight = face;
}

int Entity::setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{ // whereAm
    sf::FloatRect bound = this->getGlobalBounds();
    for (unsigned int i = 0; i < platforms.size(); i++)
    {
        if (i + 1 < platforms.size())
        {
            if (platforms[i]->getGlobalBounds().top < bound.top && bound.top < platforms[i + 1]->getGlobalBounds().top)
            {
                return current_stage = i + 1;
            }
        }
    }
    return platforms.size() - 1;
}

void Entity::updateGravity(const float &dt)
{
    //applying force of gravity
    velocity.y += gravity * dt;
    velocity.y -= 1 / 5.f * gravity * dt; // for coin
}

void Entity::updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
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
    //this->updateMovement(dt);
    this->move(velocity * dt);
}

Entity::Entity(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
               const int &len_idle, const int &len_move, const int &len_jump)
    : Animation(frame, framerate)
{
    this->setScale(6, 6);
    this->setPosition(pos);
    sf::Texture indle_texture;
    if (!indle_texture.loadFromFile("Texture/engineer character/engineer-idle.png"))
    {
        throw("Could not load texture 'Engineer Idle'");
    }
    frames_.push_back(addAnimation(frame, len_idle));
    textures_.push_back(indle_texture);
    sf::Texture run_texture;
    if (!run_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
    {
        throw("Could not load texture 'Engineer Run'");
    }
    frames_.push_back(addAnimation(frame, len_move));
    textures_.push_back(run_texture);
    sf::Texture jump_texture;
    if (!jump_texture.loadFromFile("Texture/engineer character/engineer-jump.png"))
    {
        throw("Could not load texture 'Engineer Jump'");
    }
    frames_.push_back(addAnimation(frame, len_jump));
    textures_.push_back(jump_texture);
    //animacja otrzymania obrazen
    frames_.push_back(addAnimation(sf::IntRect(frame.left,frame.top,frame.width,frame.height - 5), len_idle));
    textures_.push_back(indle_texture);
    this->setTexture(textures_[0]);
}

Entity::Entity(const std::vector<std::unique_ptr<sf::Sprite> > &platforms, const int &x,
               const sf::IntRect &frame, const float &framerate, const float &lenght)
    : Animation(frame, framerate, lenght)
{
    this->setScale(4, 4);
    sf::Texture texture;
    if (x < 9)
    {
        if (!texture.loadFromFile("Texture/MonedaR.png"))
        {
            throw("Could not load texture 'MonedaR'");
        }
        value = 25;
    }
    else if (x >= 9 && x <= 13)
    {
        if (!texture.loadFromFile("Texture/MonedaP.png"))
        {
            throw("Could not load texture 'MonedaP'");
        }
        value = 50;
    }
    else
    {
        if (!texture.loadFromFile("Texture/MonedaD.png"))
        {
            throw("Could not load texture 'MonedaD'");
        }
        value = 100;
    }
    textures_.push_back(texture);
    this->setTexture(texture);
    this->setPosition(sf::Vector2f(rand() % 1820, rand() % 1030));
    current_stage = setBounds(platforms);
    next_stage = current_stage;
    for (auto &pl : platforms)
    {
        while (pl->getGlobalBounds().intersects(this->getGlobalBounds()))
        {
            this->setPosition(sf::Vector2f(rand() % 1820, rand() % 1030));
        }
    }
}
