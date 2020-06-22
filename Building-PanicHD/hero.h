#ifndef HERO_H
#define HERO_H

#include "entity.h"
#include "object.h"

class Hero : public Entity
{
public:
    bool stunned();
    bool can_paint();
    const Object::Color &getColor_Object();
    float addScore(const float &value);
    float getScore();
    void moveSprite(const sf::Vector2f &dir, const float &dt);
    void updateMovement(const float &dt);
    void getHurt(Hero &hero, const float &dt);
    void resetScore();
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    virtual bool painting() = 0;
    sf::Vector2f view(); // not in use right now
    Hero(const sf::Vector2f &pos, const Object::Color &color);
    virtual ~Hero() = default;

private:
    bool attack = false;
    bool attack_cooldown = true;
    bool paint = false;
    bool paint_cooldown = true;
    bool untouchable = false;
    bool is_stunned = false;
    bool can_change = true;
    int score = 1000;
    float acceleration = 2400.f;
    float deceleration = 750.f;
    float attackVelocity = 1200.f;
    float maxVelocity = 450.f;
    float maxFallingVelocity = 1200.f;
    float timer = 0.f;
    float timer_elapsed = 1.f;
    float timer_reset = 0.f;
    float untouchable_timer = 0.f;
    float untouchable_reset = 0.f;
    float untouchable_elapsed = 2.0f;
    float stunned_elapsed = 1.5f;
    float snapshot_color = 0.3f;
    float change_platform_timer = 0.f;
    float change_platform_reset = 0.f;
    float change_platform_elapsed = 0.6;
    float painting_timer = 0.5f;
    float painting_stop = 0.f;
    float painting_start = 0.5f;
    Object::Color color_;
    sf::Color RGB;
    sf::SoundBuffer buffer;
    sf::Sound getHurt_effect;

protected:
    void attack_move();
    void painting_move();
    void down();
    void jump();
    void setColor_flag(Object::Color color); // not in use right now
    void cooldown(const float &dt);
    void wall_painting(const float &dt);
    void change_platform_cooldown(const float &dt);
    void untouchable_cooldown(const float &dt);
};

#endif // HERO_H
