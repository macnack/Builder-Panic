#ifndef OBJECT_H
#define OBJECT_H
#include "common_defs.h"

class Object : public sf::Sprite
{
public:
    Object(const sf::Vector2f &pos, const sf::FloatRect &rect,const sf::Texture &texture);
    Object(){}
    virtual ~Object() = default;
    enum class Color{
        Enemy = -1,
        Default,
        Player,
    };
    enum class Fill{
        one_third,
        two_thirds,
        full,
    };
    void Paint(Object::Color color);
    int getIntColor();
private:
    bool can_change_color =false;
    Object::Color color_;
    sf::Vector2f pos_;
    sf::IntRect rect_;
    //sf::Vector2f size_;
    sf::Texture texture_;
};

#endif // OBJECT_H
