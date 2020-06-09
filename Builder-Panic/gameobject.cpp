#include "gameobject.h"

GameObject::GameObject(const sf::Vector2f &pos, const sf::FloatRect &rect, const sf::Texture &texture)
    : pos_(pos), rect_(rect), texture_(texture)
{
    this->setPosition(pos_);
    this->setTexture(texture_);
    this->setTextureRect(rect_);
}

GameObject::GameObject(const sf::Vector2f &pos, const sf::Texture &texture)
    : pos_(pos), texture_(texture)
{
    this->setPosition(pos_);
    this->setTexture(texture_);
}

GameObject::~GameObject() {}
