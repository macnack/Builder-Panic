#ifndef OBJECT_H
#define OBJECT_H
#include "gameobject.h"

class Object : public GameObject
{
public:
    bool is_visible();
    const bool &can_change();
    int getIntColor();
    enum class Color{Enemy = -1, Default ,Player };
    const Object::Color &getColor_Object();
    enum class Fill{one_third, two_thirds, full, full_full};
    const Object::Fill &getFill();
    void SetFill();
    void Paint(const Object::Color &color);
    Object(const sf::Vector2f &pos, const sf::Texture &texture);
    virtual ~Object() = default;

private:
    bool can_change_color;
    bool invisible = false;
    Object::Color color_;
    Object::Fill fill_;
};

#endif // OBJECT_H
