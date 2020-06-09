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
    void SetFill();
    void Paint(Object::Color color);
    bool can_change();
    int getIntColor();
private:
    bool can_change_color;
    Object::Color color_;
    Object::Fill fill_;
    int fill = 0;
};

#endif // OBJECT_H
