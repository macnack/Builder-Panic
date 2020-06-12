#include "hero.h"



Hero::Hero(const sf::Vector2f &pos) : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 9, 8, 3)//docelowy konsturkor
{
    grounded = true;
    bounce = false;
}

float Hero::addScore(const float &value){
    return score += value;
}

float Hero::getScore(){
    return score;
}
