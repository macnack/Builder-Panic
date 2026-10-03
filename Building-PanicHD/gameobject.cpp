#include "gameobject.h"

GameObject::GameObject(const sf::Vector2f &pos, const sf::FloatRect &rect, const sf::Texture &texture)
    : pos_(pos), rect_(rect)
{
    this->setPosition(pos_);
    this->setTexture(texture);
    this->setTextureRect(rect_);
}

GameObject::GameObject(const sf::Vector2f &pos, const sf::Texture &texture)
    : pos_(pos), rect_(0, 0, 174, 192)
{
    this->setPosition(pos_);
    this->setTexture(texture);
    this->setTextureRect(rect_);
}
