#include "enemy.h"

void Enemy::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
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
    //if painting...
    this->wall_painting(dt);


    this->change_platform_cooldown(dt);
    this->change_platform();
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

Enemy::Enemy(const sf::Vector2f &pos) : Hero(pos, Object::Color::Enemy), pos_(pos)
{

}

bool Enemy::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && !stunned();
}

bool Enemy::left_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !stunned() && !painting() ;
}

bool Enemy::right_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !stunned() && !painting() ;
}

bool Enemy::jump_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !stunned() && !painting() ;
}

bool Enemy::down_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !stunned() && !painting() ;
}

bool Enemy::charge_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !stunned() && !painting();
}
