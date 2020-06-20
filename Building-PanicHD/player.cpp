#include "player.h"

void Player::loop( const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
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

Player::Player() : Hero( sf::Vector2f(825, 250), Object::Color::Player)
{

}

Player::Player(const sf::Vector2f &pos) : Hero(pos, Object::Color::Player)
{

}

bool Player::painting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
}

bool Player::left_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool Player::right_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool Player::jump_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool Player::down_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool Player::charge_move()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::C);
}


