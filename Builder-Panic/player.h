#ifndef PLAYER_H
#define PLAYER_H
#include "common_defs.h"

class Player : public sf::RectangleShape
{
public:
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    void jump();
    void down();
    void updateGravity(const float& dt);
    void updateMovement(const float& dt);
    void updateCollisions(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float& dt);
    void moveSprite(const sf::Vector2f& dir, const float& dt);
    virtual void loop(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms ,const float& dt);
    virtual void change_platform();
    Player(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size)
    {
        this->setPosition(pos);
    }
    virtual ~Player() = default;
protected:
    bool stage_down = false;
    int current_stage = 4;
    int next_stage = current_stage;
    double attack = 1;
    double healt = 5;
    sf::Vector2f size;
    sf::Vector2f velocity;
    float gravity = 2000;
    float acceleration = 4800.f;
    float deceleration = 1500;
    bool grounded = false;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 500.f;
};

class Enemy : public Player{
public:
    Enemy(const sf::Vector2f &size, const sf::Vector2f &pos) : Player(size, pos){
        grounded = true;
    }
};


#endif // PLAYER_H
