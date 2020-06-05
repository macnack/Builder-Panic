#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "common_defs.h"
class Player : public sf::RectangleShape
{
public:
    Player(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size)
    {
        sf::RectangleShape::setPosition(pos);
    }
    Player(){}
    void setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms){
        sf::FloatRect bound = this->getGlobalBounds();
        for(unsigned int i = 0; i < platforms.size(); i++){
            if( platforms[i]->getGlobalBounds().top < bound.top
                    && bound.top < platforms[i+1]->getGlobalBounds().top){
                stage = i+1;
            }
        }
    }
    void move_(const sf::Time &elapsed);
    void paint();
    int stage;
private:
    double attack = 1;
    double healt = 5;
    sf::Vector2f size;
    //sf::Vector2f::Vector2(50,100) size ;

    sf::RectangleShape body_ ;
};

#endif // PLAYER_H
