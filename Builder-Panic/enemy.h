#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

class Enemy : public Hero
{
public:
    Enemy(const sf::Vector2f &pos) : Hero(pos)
    {
        this->setColor(Object::Color::Enemy);
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    virtual ~Enemy() = default;

private:
};

#endif // ENEMY_H
