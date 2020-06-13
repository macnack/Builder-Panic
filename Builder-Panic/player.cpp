#include "player.h"

void Player::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
    }
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        attack_move();
    }
    this->cooldown(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}


void Player::change_platform()
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


