#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

class Enemy : public Hero
{
public:
    Enemy(const sf::Vector2f &pos) : Hero(pos) //docelowy konstruktor
    {
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    virtual ~Enemy() = default;
    const Object::Color &getColor(){
        return color;
    }
private:
    int rando;
    Object::Color color = Object::Color::Enemy;
};

#endif // ENEMY_H
