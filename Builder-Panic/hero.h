#ifndef HERO_H
#define HERO_H

#include "entity.h"
#include "object.h"

class Hero : public Entity
{
public:
    bool stunned();
    bool can_paint();
    const Object::Color &getColor();
    float addScore(const float &value);
    float getScore();
    void moveSprite(const sf::Vector2f &dir, const float &dt);
    void updateMovement(const float &dt);
    void getHurt(Hero &hero, const float &dt);
    void setColor(Object::Color color);
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    virtual bool painting() = 0;
    Hero(const sf::Vector2f &pos);
    virtual ~Hero() = default;

private:
    bool attack = false;
    bool attack_cooldown = true;
    bool paint = false;
    bool paint_cooldown = true;
    bool untouchable = false;
    bool can_change = true;
    float score = 1000;
    float acceleration = 2400.f;
    float deceleration = 750.f;
    float attackVelocity = 800.f;
    float maxVelocity = 250.f;
    float maxFallingVelocity = 850.f;
    float timer = 0.f;
    float untouchable_timer = 0.f;
    float change_platform_timer = 0.f;
    float painting_timer = 1.f;
    Object::Color color_;

protected:
    void attack_move();
    void painting_move();
    void down();
    void jump();
    void cooldown(const float &dt);
    void wall_painting(const float &dt);
    void change_platform_cooldown(const float &dt);
    void untouchable_cooldown(const float &dt);
};

#endif // HERO_H
