#ifndef COIN_H
#define COIN_H
#include "gameobject.h"

class Coin : public GameObject
{
public:
    Coin(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length);
    void addAnimation(const int length);
    void playAnimation(const float& dt);
private:
    float framerate_ = 0.f;
    sf::IntRect frame_;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
    float timer = 0.f;
};

#endif // COIN_H
