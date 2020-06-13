#ifndef HERO_H
#define HERO_H

#include "entity.h"

class Hero : public Entity
{
public:
    float addScore(const float &value);
    float getScore();
    void moveSprite(const sf::Vector2f &dir, const float &dt);
    void updateMovement(const float &dt);
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    void getHurt(Hero &hero){
        if(hero.getGlobalBounds().intersects(this->getGlobalBounds())){
            if(attack == true){
                if(!untouchable){
                    hero.velocity.y -= 250;
                    std::cerr << "dostaje bencki" << std::endl;
                    untouchable = true;
                }
            }
        }
    }
    Hero(const sf::Vector2f &pos);
    void untouchable_cooldown(const float &dt);
    virtual ~Hero() = default;
private:
    float score = 1000;
protected:
    void cooldown(const float &dt);
    void attack_move();
    void down();
    void jump();
protected:
    float acceleration = 2400.f;
    float deceleration = 750.f;
    float maxFallingVelocity = 850.f;
    float maxVelocity = 250.f;
    float attackVelocity = 800.f;
    float timer = 0.f;
    float untouchable_timer = 0.f;
    bool attack_cooldown = true;
    bool attack = false;
    bool untouchable = false;
};

#endif // HERO_H
