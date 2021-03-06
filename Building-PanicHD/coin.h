#ifndef COIN_H
#define COIN_H

#include "hero.h"

class Coin : public Entity
{
public:
    Coin(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    bool is_collected(Hero &gracz); // not in use
    bool is_collected(Hero &gracz1, Hero &gracz2);
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);

private:
    int getValue();
};

#endif // COIN_H
