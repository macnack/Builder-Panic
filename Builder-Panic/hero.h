#ifndef HERO_H
#define HERO_H

#include "entity.h"

class Hero : public Entity
{
public:
    void moveSprite(const sf::Vector2f &dir, const float &dt)
    {
        //incrasing speed in the inputed dirction
        velocity += dir * (dt * acceleration);
    }
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    Hero(const sf::Vector2f &pos);
    virtual ~Hero() = default;
    float addScore(const float &value);
    float getScore();
    void updateMovement(const float &dt)
    {
        if(velocity.x != 0){
            switcher = 1;
        }
        if (velocity.y > 0.f)
        {
            //Max falling velocity check
            if (velocity.y > maxFallingVelocity)
            {
                velocity.y = maxFallingVelocity;
            }
        }
        if (velocity.x > 0.f)
        { //right
            //deceleration
            velocity.x -= deceleration * dt;
            if (velocity.x < 0.f)
                velocity.x = 0.f;
            //max velocity check
            if (velocity.x > maxVelocity ){
                velocity.x = maxVelocity;
            }
            if (attack == false && timer < 0.1 ){
                velocity.x = attackVelocity;
            }
        }
        else if (velocity.x < 0.f)
        { //if going left
            //decelaretion

            velocity.x += deceleration * dt;
            if (velocity.x > 0.f)
                velocity.x = 0.f;
            //max velocity check
            if (velocity.x < -maxVelocity ){
                velocity.x = -maxVelocity;
            }
            if (attack == false && timer < 0.1 ){
                velocity.x = -std::abs(attackVelocity);
            }
        }
        this->setTexture(textures_[switcher]);
        this->playAnimation(dt);
    }
private:
    float score = 1000;
protected:
    void cooldown(const float &dt){
        timer += dt;
        if(!attack){
            if(timer > 1){
                timer = 0.f;
                attack = true;
            }
        }else{
            timer = 0.f;
        }
    }
    void attack_move(){
        attack = false;
    }
    void down(){
        if (stage_down == true && current_stage < 4)
        {
            velocity.y += 200;
            current_stage += 1;
            next_stage = current_stage;
            grounded = false;
            switcher = 2;
        }
    }
    void jump(){
        if (grounded == true && current_stage > 1)
        {
            current_stage -= 1;
            next_stage = current_stage;
            stage_down = false;
        }
        if (grounded)
        {
            velocity.y -= 850;
            switcher = 2;
        }
    }
protected:
    float acceleration = 2400.f;
    float deceleration = 750.f;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 250.f;
    float attackVelocity = 800.f;
    float timer = 0.f;
    bool attack = true;
};

#endif // HERO_H
