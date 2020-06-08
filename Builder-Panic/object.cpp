#include "object.h"


Object::Object(const sf::Vector2f &pos, const sf::FloatRect &rect, const sf::Texture &texture): pos_(pos), rect_(rect), texture_(texture){
    this->setPosition(pos_);
    this->setTexture(texture_);
    this->setTextureRect(rect_);
    color_ = Color::Default;
    can_change_color = true;
}

void Object::Paint(const Object::Color color){
    if(can_change_color){
    color_ = color;
    switch (color) {
    case Color::Enemy:
        this->setColor(sf::Color(0,255,255));
        //this->setTextureRect(sf::IntRect(0,95,91,45));
        break;
    case Color::Player:
        this->setColor(sf::Color(0,0,255));
        //this->setTextureRect(sf::IntRect(0,0,91,90));
        break;
    case Color::Default:
        this->setColor(sf::Color(255,255,255));
        break;
    }
    }
}

int Object::getIntColor(){
    switch (color_) {
    case Color::Enemy:
        return -1;
    case Color::Default:
        return 0;
    case Color::Player:
        return 1;
    }
    return 0;
}
