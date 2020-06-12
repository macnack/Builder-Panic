#include "player.h"

void Player::loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            if(attak){
                velocity.x = 0;
                velocity.x = -std::abs(maxVelocity-1);
                 std::cerr << "pocisk twoja stara nosi pierogi w siatce" << std::endl;
            }
            attak = false;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            if(attak){
                velocity.x = 0;
                velocity.x = maxVelocity-1;
                 std::cerr << "pocisk twoja stara nosi pierogi w siatce" << std::endl;
            }
            attak = false;
        }
    }
    this->attack(dt);
    this->updateMovement(dt);
    this->updateCollisions(platforms, dt);
}
void Player::attack(const float &dt){
    timer += dt;
    if(!attak){
        if(timer > 1){
            attak = true;
            timer = 0;
        }
    }else{
        timer = 0.f;
    }

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

