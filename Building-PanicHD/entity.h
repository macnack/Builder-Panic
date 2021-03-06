#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"
class Entity : public Animation
{
public:
    void setFaceRight(const bool &face);
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    void updateGravity(const float &dt);
    void updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    Entity(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
           const int &len_idle, const int &len_move, const int &len_jump);
    Entity(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const int &x,
           const sf::IntRect &frame, const float &framerate, const float &lenght);
    virtual ~Entity() = default;
protected:
    int value;
    bool bounce = false;
    bool stage_down = false;
    bool grounded = false;
    int current_stage = 3;
    int next_stage = current_stage;
    float gravity = 2000;
    float height_screen = 1080;
    float width_screen = 1920;
    sf::Vector2f velocity;
};

#endif // ENTITY_H
