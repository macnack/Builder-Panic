#include "enemy.h"

void Enemy::loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if( !stunned() && painting() == false )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        {
            this->attack_move();
        }
    }
    this->change_platform_cooldown(dt);
    this->change_platform();
    this->cooldown(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}

void Enemy::change_platform()
{
    if( !stunned() && painting() == false )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            this->down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->jump();
        }
    }
}

bool Enemy::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::M) && !stunned();
}
