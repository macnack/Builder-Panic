#include "coin.h"

Coin::Coin(const sf::Vector2f &pos, const sf::Texture &texture, const sf::IntRect &frame, const float &framerate, const int &length)
    : GameObject(pos, texture), framerate_(framerate), frame_(frame){
    this->addAnimation(length);
    this->setScale(3,3);
}

void Coin::addAnimation(const int length) {
    this->startRect = sf::IntRect(frame_.top * frame_.width,
                                  frame_.top * frame_.height,
                                  frame_.width,
                                  frame_.height);

    this->currentRect = this->startRect;

    this->endRect = sf::IntRect(frame_.top * frame_.width + frame_.width * (length - 1),
                                (frame_.top)*frame_.height,
                                frame_.width,
                                frame_.height);

    this->setTextureRect(this->startRect);
}

void Coin::playAnimation(const float &dt) {
    this->timer += dt;

    if (this->timer > 1 / this->framerate_) {
        this->timer = 0.f;

        if (this->currentRect != this->endRect) {
            this->currentRect.left += this->frame_.width;
        }
        else {
            this->currentRect = this->startRect;
        }
        this->setTextureRect(this->currentRect);
    }
}
