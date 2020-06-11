#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

class Player : public Entity
{
public:
    Player(const sf::Vector2f &pos) : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 9, 8, 3)
    {
        grounded = true;
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();

private:
};

#endif // PLAYER_H
