#ifndef PLAYER_H
#define PLAYER_H
#include "hero.h"


class Player : public Hero
{
public:
    Player(const sf::Vector2f &pos) : Hero(pos) //docelowy konstruktor
    {
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    virtual ~Player() = default;
private:
    int rando;
};

#endif // PLAYER_H
