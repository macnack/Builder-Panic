#ifndef OBJECT_H
#define OBJECT_H
#include "gameobject.h"

class Object : public GameObject
{
public:
    enum class Color{Enemy = -1, Default ,Player };
    enum class Fill{one_third, two_thirds, full, full_full};
    const Object::Color &getColor_Object();
    const Object::Fill &getFill();
    bool is_visible();
    int getIntColor();
    void SetFill();
    void Paint(const Object::Color &color);
    const bool &can_change();
    Object(const sf::Vector2f &pos, const sf::Texture &texture);
    virtual ~Object() = default;

private:
    bool can_change_color;
    bool invisible = false;
    Object::Color color_;
    Object::Fill fill_;
};

#endif // OBJECT_H
