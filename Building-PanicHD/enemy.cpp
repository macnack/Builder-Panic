#include "enemy.h"

void Enemy::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    this->change_platform_cooldown(dt);
    if( !stunned() && !painting() )
    {
        if ( this->left_move() )
        {
            this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
        }
        else if ( this->right_move() )
        {
            this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
        }
        if( this->charge_move() )
        {
            this->attack_move();
        }
        this->change_platform();
    }

    if( !stunned() )
    {
        //if painting...
        this->wall_painting(dt);
    }

    this->cooldown(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}


void Enemy::change_platform()
{
    if ( this->down_move() )
    {
        this->down();
    }
    if ( this->jump_move() )
    {
        this->jump();
    }
}

Enemy::Enemy() : Hero(sf::Vector2f(1025, 250), Object::Color::Enemy)
{

}

Enemy::Enemy(const sf::Vector2f &pos) : Hero(pos, Object::Color::Enemy)
{

}

bool Enemy::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
}

bool Enemy::left_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool Enemy::right_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ;
}

bool Enemy::jump_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

bool Enemy::down_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  ;
}

bool Enemy::charge_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
}
