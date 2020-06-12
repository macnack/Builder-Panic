#ifndef HERO_H
#define HERO_H

#include "entity.h"

class Hero : public Entity
{
public:
    Hero(const sf::Vector2f &pos) : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 9, 8, 3)//docelowy konsturkor
    {
        grounded = true;
        bounce = false;
    }
    Hero(const sf::Vector2f &pos, const int &framerate)
        : Entity(pos, sf::IntRect(0, 0, 16, 28), framerate)
    {
        grounded = true;
    }
    void moveSprite(const sf::Vector2f &dir, const float &dt)
    {
        //incrasing speed in the inputed dirction
        velocity += dir * (dt * acceleration);
    }
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    virtual ~Hero() = default;
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
