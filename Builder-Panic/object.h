#ifndef OBJECT_H
#define OBJECT_H
#include "common_defs.h"

class Object : public sf::Sprite
{
public:
    Object(sf::Vector2f pos, sf::FloatRect rect, sf::Texture texture);
    Object(){}
    virtual ~Object() = default;
    enum class Color{
        Enemy = -1,
        Default,
        Player,
    };
    void Paint(Object::Color color);
    int getIntColor();
private:
    Object::Color color_;
    sf::Vector2f pos_;
    sf::IntRect rect_;
    //sf::Vector2f size_;
    sf::Texture texture_;
};

#endif // OBJECT_H
