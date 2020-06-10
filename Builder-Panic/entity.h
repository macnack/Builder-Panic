#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"

class Entity : public Animation
{
public:
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    void updateGravity(const float &dt);
    void updateMovement(const float &dt);
    void updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void moveSprite(const sf::Vector2f &dir, const float &dt);
    virtual void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt) = 0;
    virtual void change_platform() = 0;
    Entity(const sf::Vector2f &pos ,const Animation &sprite) : Animation(sprite){
        sprite_.push_back(sprite);
        this->setPosition(pos);
    }
    Entity(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length): Animation(pos, texture,frame,framerate, length){
        this->setScale(3,3);
    }

    virtual ~Entity() = default;
protected:
    std::vector<Animation> sprite_;
    void jump();
    void down();
    bool stage_down = false;
    int current_stage = 4;
    int next_stage = current_stage;
    sf::Vector2f size;
    sf::Vector2f velocity;
    float gravity = 2000;
    float acceleration = 4800.f;
    float deceleration = 1500;
    bool grounded = false;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 500.f;
};
#endif // ENTITY_H
