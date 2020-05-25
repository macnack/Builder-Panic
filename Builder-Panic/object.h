#ifndef OBJECT_H
#define OBJECT_H
#include "common_defs.h"

class Object : public sf::Sprite
{
public:
    Object(sf::Vector2f pos, sf::IntRect rect): pos_(pos), rect_(rect){
        this->setPosition(pos_);
        this->setTextureRect(rect_);
    }
    Object(){}
    virtual ~Object() = default;
private:
    bool draw = true;
    sf::Vector2f pos_;
    sf::IntRect rect_;
    //sf::Vector2f size_;
    //sf::Texture texture;
};

#endif // OBJECT_H
