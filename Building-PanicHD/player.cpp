#include "player.h"

void Player::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
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


void Player::change_platform()
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

Player::Player(const sf::Vector2f &pos) : Hero(pos, Object::Color::Player)
{

}

bool Player::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !stunned();
}

bool Player::left_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !stunned() && !painting() ;
}

bool Player::right_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !stunned() && !painting() ;
}

bool Player::jump_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !stunned() && !painting() ;
}

bool Player::down_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !stunned() && !painting() ;
}

bool Player::charge_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !stunned() && !painting();
}


