#ifndef COIN_H
#define COIN_H
#include "animation.h"

class Coin : public Animation
{
public:
    Coin(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length): Animation(pos, texture,frame,framerate, length){
        value = 100;
        bound = this->getLocalBounds();
    }
private:
    int value;
    sf::FloatRect bound;
};

#endif // COIN_H
