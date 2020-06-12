#ifndef PLAYER_H
#define PLAYER_H

#include "coin.h"
#include "object.h"

class Player : public Hero
{
public:
    Player(const sf::Vector2f &pos) : Hero(pos) //docelowy konstruktor
    {
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    virtual ~Player() = default;
    const Object::Color &getColor(){
        return color;
    }
private:
    int rando;
    Object::Color color = Object::Color::Player;
};

#endif // PLAYER_H
