#include "player.h"

void Player::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if( !stunned() && painting() == false )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
        }
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            attack_move();
        }
    }
    this->change_platform_cooldown(dt);
    this->painting_cooldown(dt);
    this->change_platform();
    this->cooldown(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}


void Player::change_platform()
{
    if( !stunned() && painting() == false )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            this->down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            this->jump();
        }
    }
}

bool Player::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !stunned();
}


