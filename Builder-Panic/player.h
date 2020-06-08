#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "common_defs.h"
class Player : public sf::RectangleShape
{
public:
    Player(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size)
    {
        sf::RectangleShape::setPosition(pos);

    }
    Player(){}
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms){ // whereAm
        sf::FloatRect bound = this->getGlobalBounds();
        for(unsigned int i = 0; i < platforms.size(); i++){
            if( i+1 < platforms.size()){
                if( platforms[i]->getGlobalBounds().top < bound.top
                        && bound.top < platforms[i+1]->getGlobalBounds().top){
                    return current_stage = i+1;
                }
            }
        }
        return platforms.size()-1;
    }
    void jump() {
        if (this->grounded == true) {
            this->velocity.y -= 1000;
        }
        if(current_stage > 1)
            current_stage -= 1;
        next_stage = current_stage;
    }
    void down(){
        if (this->stage_down == true && current_stage < 4){
            this->velocity.y += 1000;
            current_stage += 1;
            next_stage = current_stage;
        }
    }
    void move_(const sf::Time &elapsed);
    void moveSprite(const sf::Vector2f& dir, const float& dt) {
        //incrasing speed in the inputed dirction
        this->velocity += dir * (dt * this->acceleration);
    }
    void updateGravity(const float& dt) {
        //applying force of gravity
        this->velocity.y += this->gravity * dt;
    }
    void updateMovement(const float& dt) {
        this->updateGravity(dt);
        if (this->velocity.y > 0.f) {
            //Max falling velocity check
            if (this->velocity.y > this->maxFallingVelocity) {
                this->velocity.y = this->maxFallingVelocity;
            }
        }
        if (this->velocity.x > 0.f) { //if going in right diraction
            //deceleration
            this->velocity.x -= this->deceleration * dt;
            if (this->velocity.x < 0.f)
                this->velocity.x = 0.f;
            //max velocity check
            if (this->velocity.x > this->maxVelocity)
                this->velocity.x = maxVelocity;
        }
        else if (this->velocity.x < 0.f) { //if going left
            //decelaretion
            this->velocity.x += deceleration * dt;
            if (this->velocity.x > 0.f)
                this->velocity.x = 0.f;
            //max velocity check
            if (this->velocity.x < -this->maxVelocity)
                this->velocity.x = -this->maxVelocity;
        }
        this->move(this->velocity * dt);
    }
    void updateCollisions(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float& dt) {
        grounded = false;
        sf::FloatRect playerBounds = this->getGlobalBounds();
        sf::FloatRect playerBoundsNext = this->getGlobalBounds();
        playerBoundsNext.left = this->getPosition().x + this->velocity.x * dt;
        playerBoundsNext.top = this->getPosition().y + this->velocity.y * dt;
        current_stage = setBounds(platforms);
        sf::FloatRect platformBounds = platforms[next_stage]->getGlobalBounds();
        if(platformBounds.intersects(playerBoundsNext)){ //bottom
            if (playerBounds.top < platformBounds.top
                    && playerBounds.top + playerBounds.height < platformBounds.top + platformBounds.height
                    && playerBounds.left < platformBounds.left + platformBounds.width
                    && playerBounds.left + playerBounds.width > platformBounds.left
                    )
            {
                this->velocity.y = 0;
                this->setPosition(playerBounds.left, platformBounds.top - playerBounds.height);
                grounded = true;
                stage_down = true;
            }
        }
        if(playerBounds.top + playerBounds.height > 800){ //zapobiega spadaniu
            this->setPosition(playerBounds.left, platformBounds.top - playerBounds.height);
        }
        this->updateMovement(dt);
    }
    void loop(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms ,const float& dt){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            this->moveSprite(sf::Vector2f(-1.f, 0.f), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            this->moveSprite(sf::Vector2f(1.f, 0.f), dt);
        }
        this->updateCollisions(platforms, dt);
    }
    void change_platform(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            this->down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            this->jump();
        }
    }
    void paint();
    int current_stage = 4;
    int next_stage = current_stage;
    bool stage_down = false;
private:
    //std::vector<std::unique_ptr<sf::Sprite>> platforms_;
    double attack = 1;
    double healt = 5;
    sf::Vector2f size;
    //sf::Vector2f::Vector2(50,100) size ;
    sf::Vector2f velocity;
    float gravity = 2000;
    float acceleration = 4800.f;
    float deceleration = 1500;
    bool grounded = false;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 500.f;

    sf::RectangleShape body_ ;
};

#endif // PLAYER_H
