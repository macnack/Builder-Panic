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
    Entity(const sf::Vector2f &pos, const sf::Texture &texture,
           const sf::IntRect &frame,
           const float &framerate, const int &length) : Animation(frame, framerate, length)
    {
        this->setScale(3.5, 3.5);
        this->setPosition(pos);
        frames_.push_back(addAnimation(sf::IntRect(0, 0, 16, 28), 8));
        textures_.push_back(texture);
        sf::Texture run_texture;
        if (!run_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
        {
            throw("Could not load texture 'Engineer Idle'");
        }
        frames_.push_back(addAnimation(sf::IntRect(0, 0, 16, 28), 7));
        textures_.push_back(run_texture);
        sf::Texture jump_texture;
        if (!jump_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
        {
            throw("Could not load texture 'Engineer Idle'");
        }
        frames_.push_back(addAnimation(sf::IntRect(0, 0, 16, 28), 7));
        textures_.push_back(run_texture);
        this->setTexture(textures_[0]);
    }
    virtual ~Entity() = default;

protected:
    bool stage_down = false;
    bool grounded = false;
    void down();
    void jump();
    int current_stage = 4; //define?
    int next_stage = current_stage;
    sf::Vector2f velocity;
    float gravity = 2000;
    float acceleration = 2400.f;
    float deceleration = 750.f;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 250.f;

};
#endif // ENTITY_H
