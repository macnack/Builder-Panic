#ifndef COIN_H
#define COIN_H

#include "hero.h"


class Coin : public Entity
{
public:
    Coin(const std::vector<std::unique_ptr<sf::Sprite>> &platforms) : Entity(platforms,rand() % 15,sf::IntRect(0, 0, 16, 16), 7, 4)
    {
        bounce = true;
    }
    bool is_collected(const Hero &gracz);
    virtual ~Coin()
    {
        std::cerr << "Collected coin +" << std::endl;
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt){
        this->updateCollisions(platforms, dt);
        this->playAnimation(dt);
    }
private:
    int value;

};

#endif // COIN_H
