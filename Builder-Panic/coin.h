#ifndef COIN_H
#define COIN_H
#include "animation.h"
#include "entity.h"
class Coin : public Animation
{
public:
    Coin(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length): Animation(pos, texture,frame,framerate, length){
        value = 100;
        this->setScale(3,3);
        bound = this->getLocalBounds();
    }
    bool is_collected(Entity &postac){
        if( this->getGlobalBounds().intersects(postac.getGlobalBounds())){
            return true;
        }
        return false;
    }
private:
    int value;
    sf::FloatRect bound;
};

#endif // COIN_H
