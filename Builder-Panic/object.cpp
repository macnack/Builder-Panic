#include "object.h"

Object::Object(const sf::Vector2f &pos, const sf::FloatRect &rect, const sf::Texture &texture)
    : GameObject(pos, rect, texture)
{
    color_ = Color::Default;
    fill_ = Fill::one_third;
    can_change_color = true;
    this->setOrigin(this->getLocalBounds().left + this->getLocalBounds().width, this->getLocalBounds().top + this->getLocalBounds().height);
    this->setRotation(180);
}

void Object::SetFill()
{
    switch (fill_)
    {
    case Object::Fill::one_third:
        this->setTextureRect(sf::IntRect(0, 0, 91, 45));
        fill_ = Fill::two_thirds;
        break;
    case Object::Fill::two_thirds:
        this->setTextureRect(sf::IntRect(0, 0, 91, 90));
        fill_ = Fill::full;
        break;
    case Object::Fill::full:
        this->setTextureRect(sf::IntRect(0, 0, 91, 140));
        fill_ = Fill::full_full;
        break;
    case Object::Fill::full_full:
        std::cerr << "Can't change color" << std::endl; // do usuniecia!!
        can_change_color = false;
        break;
    }
}
void Object::Paint(const Object::Color color)
{
    color_ = color;
    switch (color)
    {
    case Color::Enemy:
        this->setColor(sf::Color(0, 255, 255));
        break;
    case Color::Player:
        this->setColor(sf::Color(0, 0, 255));
        break;
    case Color::Default:
        this->setColor(sf::Color(255, 255, 255));
        break;
    }
}

const bool &Object::can_change()
{
    return can_change_color;
}

int Object::getIntColor()
{
    switch (color_)
    {
    case Color::Enemy:
        return -1;
    case Color::Default:
        return 0;
    case Color::Player:
        return 1;
    }
    return 0;
}
