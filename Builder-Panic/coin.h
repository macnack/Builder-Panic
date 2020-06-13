#ifndef COIN_H
#define COIN_H

#include "hero.h"

class Coin : public Entity
{
public:
    Coin(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    bool is_collected(Hero &gracz);
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    bool loop(Hero &gracz1, Hero &gracz2, const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);

private:
    int getValue();
};

#endif // COIN_H
