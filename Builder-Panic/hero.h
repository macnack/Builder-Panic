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
            if (velocity.x > maxVelocity)
                velocity.x = maxVelocity;
        }
        else if (velocity.x < 0.f)
        { //if going left
            //decelaretion

            velocity.x += deceleration * dt;
            if (velocity.x > 0.f)
                velocity.x = 0.f;
            //max velocity check
            if (velocity.x < -maxVelocity)
                velocity.x = -maxVelocity;
        }
        this->setTexture(textures_[switcher]);
        this->playAnimation(dt);
    }
private:
    float score = 1000;
protected:
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
};

#endif // HERO_H
