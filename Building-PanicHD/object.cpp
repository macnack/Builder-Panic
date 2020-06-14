#include "object.h"

Object::Object(const sf::Vector2f &pos, const sf::Texture &texture)
    : GameObject(pos, texture)
{
    color_ = Color::Default;
    fill_ = Fill::one_third;
    invisible = false;
    can_change_color = true;
    this->setOrigin(this->getLocalBounds().left + this->getLocalBounds().width, this->getLocalBounds().top + this->getLocalBounds().height);
    this->setRotation(180);
}

void Object::SetFill()
{
    switch (fill_)
    {
    case Object::Fill::one_third:
        this->setTextureRect(sf::IntRect(0, 0, 187, 64));
        invisible = true;
        fill_ = Fill::two_thirds;
        break;
    case Object::Fill::two_thirds:
        this->setTextureRect(sf::IntRect(0, 0, 187, 128));
        fill_ = Fill::full;
        break;
    case Object::Fill::full:
        this->setTextureRect(sf::IntRect(0, 0, 187, 192));
        fill_ = Fill::full_full;
        break;
    case Object::Fill::full_full:
        can_change_color = false;
        break;
    }
}
void Object::Paint(const Object::Color &color)
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

const Object::Color &Object::getColor_Object()
{
    return color_;
}

const Object::Fill &Object::getFill()
{
    return fill_;
}

bool Object::is_visible()
{
    return invisible;
}