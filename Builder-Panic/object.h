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
        full_full,
    };
    void SetFill();
    void Paint(Object::Color color);
    const bool &can_change();
    int getIntColor();
    const Object::Fill &getFill(){
        return fill_;
    }

private:
    bool can_change_color;
    Object::Color color_;
    Object::Fill fill_;
    int fill = 0;
};

#endif // OBJECT_H
