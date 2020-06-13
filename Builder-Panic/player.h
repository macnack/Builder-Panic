#ifndef PLAYER_H
#define PLAYER_H

#include "coin.h"

class Player : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    bool painting();
    Player(const sf::Vector2f &pos) : Hero(pos)
    {
        this->setColor(Object::Color::Player);
    }
    virtual ~Player() = default;

private:
};

#endif // PLAYER_H
