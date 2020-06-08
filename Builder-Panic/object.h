#ifndef OBJECT_H
#define OBJECT_H
#include "gameobject.h"

class Object : public GameObject
{
public:
    Object(const sf::Vector2f &pos, const sf::FloatRect &rect,const sf::Texture &texture);
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
};

#endif // OBJECT_H
