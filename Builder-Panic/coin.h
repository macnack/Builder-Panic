#ifndef COIN_H
#define COIN_H
#include "animation.h"
#include "entity.h"
class Coin : public Animation
{
public:
    //    Coin(const sf::Vector2f &pos, const sf::Texture &texture,
    //         const sf::IntRect &frame,
    //         const float &framerate, const int &length): Animation(pos, texture,frame,framerate, length){
    //        value = 100;
    //        this->setScale(3,3);
    //        bound = this->getLocalBounds();
    //    } // old constructor to rm
    void random_coin(const int &x){
        if(x < 9){
            value = 50;
            if (!texture.loadFromFile("Texture/MonedaR.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }else if (x >= 9 && x < 13){
            value = 100;
            if (!texture.loadFromFile("Texture/MonedaP.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }else{
            value = 150;
            if (!texture.loadFromFile("Texture/MonedaD.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }
    }
    Coin(const sf::Vector2f &pos): Animation(sf::IntRect(0, 0, 16, 16), 7, 4){
        random_coin(rand()%15);
        this->setPosition(pos);
        this->setScale(3,3);
        this->setTexture(texture);
        bound = this->getLocalBounds();
    }
    Coin(): Animation(sf::IntRect(0, 0, 16, 16), 7, 4){
        random_coin(rand()%15);
        this->setPosition(sf::Vector2f(rand()%700, rand()%500));
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
    ~Coin(){
        std::cerr << "Collected coin +" << value << std::endl;
    }
private:
    int value;
    sf::FloatRect bound;
    sf::Texture texture;
};

#endif // COIN_H
