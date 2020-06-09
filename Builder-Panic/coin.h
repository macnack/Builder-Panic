#ifndef COIN_H
#define COIN_H
#include "gameobject.h"

class Coin : public GameObject
{
public:
    Coin(const sf::Vector2f &pos, const sf::Texture &texture) : GameObject(pos, sf::FloatRect(0,0,0,0),texture){

    }
};

#endif // COIN_H
