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
    Coin(const sf::Vector2f &pos): Animation(sf::IntRect(0, 0, 16, 16), 7, 4){
        if (!texture.loadFromFile("Texture/MonedaD.png"))
        {
            throw("Could not load texture 'Coin'");
        }
        value = 100;
        this->setPosition(pos);
        this->setScale(3,3);
        this->setTexture(texture);
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
    sf::Texture texture;
};

#endif // COIN_H
