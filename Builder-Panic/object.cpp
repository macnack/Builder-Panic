#include "object.h"


void Object::Paint(Object::Color color){
    color_ = color;
    switch (color) {
    case Color::Enemy:
        this->setColor(sf::Color(0,255,255));
        break;
    case Color::Player:
        this->setColor(sf::Color(0,0,255));
        break;
    case Color::Default:
        this->setColor(sf::Color(124,124,124));
        break;
    }
}

Object::Color Object::getColor(){
    return color_;
}
