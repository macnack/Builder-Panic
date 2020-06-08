#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "common_defs.h"

class GameObject : public sf::Sprite{
public:
    GameObject(const sf::Vector2f &pos, const sf::FloatRect &rect,const sf::Texture &texture);
private:
    sf::Vector2f pos_;
    sf::IntRect rect_;
    sf::Texture texture_;
};

#endif // GAMEOBJECT_H
