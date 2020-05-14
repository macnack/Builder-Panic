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
    void setBounds(r_vec);
    void move(const sf::Time &elapsed);
    void paint();
private:
    double attack = 1;
    double healt = 5;
    sf::Vector2f size;

    //sf::Vector2f::Vector2(50,100) size ;

    sf::RectangleShape body_ ;
};

#endif // PLAYER_H
