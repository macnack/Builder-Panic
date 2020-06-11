#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
          const int &length) : Entity(pos, frame, framerate, length)
    {
        grounded = true;
        rando = rand() % 3 - 1;
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();

private:
    int rando;
};

#endif // ENEMY_H
