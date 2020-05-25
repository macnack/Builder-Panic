#ifndef OBJECT_H
#define OBJECT_H
#include "common_defs.h"

class Object : public sf::Shape
{
public:
    Object(sf::Vector2f pos, sf::IntRect rect): pos_(pos), rect_(rect){
        this->setPosition(pos_);
        this->setTextureRect(rect_);
    }
private:
    bool draw = true;
    sf::Vector2f pos_;
    //sf::Vector2f size_;
    sf::IntRect rect_;
    //sf::Texture texture;
};

#endif // OBJECT_H
