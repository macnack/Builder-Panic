#ifndef COIN_H
#define COIN_H

#include "player.h"
#include "scena.h"

class Coin : public Entity
{
public:
    Coin() : Entity(rand() % 15,sf::IntRect(0, 0, 16, 16), 7, 4)
    {
        bounce = true;
    }
    bool is_collected(const Player &gracz);
    virtual ~Coin()
    {
        std::cerr << "Collected coin +" << std::endl;
    }
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt){
        this->updateCollisions(platforms, dt);
        this->playAnimation(dt);
    }
private:
    std::vector<std::unique_ptr<sf::Sprite>> platforms;
    int value;

};

#endif // COIN_H
