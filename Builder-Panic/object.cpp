#include "object.h"

Object::Object(const sf::Vector2f &pos, const sf::FloatRect &rect, const sf::Texture &texture)
    : GameObject(pos,rect,texture){
    color_ = Color::Default;
    fill_ = Fill::none;
    this->setOrigin(this->getLocalBounds().left+this->getLocalBounds().width, this->getLocalBounds().top+this->getLocalBounds().height);
    this->setRotation(180);
    can_change_color = true;
}

void Object::SetFill(){
    if( fill == 0){
        ++fill;
        std::cerr << "Fill: " << fill << std::endl;
    }
    else if( fill == 1){
        ++fill;
        std::cerr << "Fill: " << fill << std::endl;
    }
    else if( fill == 2){
        ++fill;
        std::cerr << "Fill: " << fill << std::endl;
    }
}

void Object::ChangeFill(){
    if( fill == 0){
        this->setTextureRect(sf::IntRect(0,0,91,45));
    }
    else if( fill == 1){
        this->setTextureRect(sf::IntRect(0,0,91,90));
    }
    else if( fill == 2){
        this->setTextureRect(sf::IntRect(0,0,91,140));
    }
}

void Object::Paint(const Object::Color color){
    if(can_change_color){
        color_ = color;
        switch (color) {
        case Color::Enemy:
            this->setColor(sf::Color(0,255,255));
            //this->setTextureRect(sf::IntRect(0,0,91,45));
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
