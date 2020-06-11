#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

class Player : public Entity
{
public:
    Player(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
           const int &length) : Entity(pos, frame, framerate, length)
    {
        grounded = true;
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();

private:
};

#endif // PLAYER_H
