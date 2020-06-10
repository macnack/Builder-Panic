#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobject.h"

class Animation : public sf::Sprite
{
public:
    Animation(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
              const float &framerate, const int &length)
        : framerate_(framerate),  texture_(texture),  frame_(frame)
    {
        this->setPosition(pos);
        this->setTexture(texture_);
        this->addAnimation(length);
    }
    Animation(const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length)
        : framerate_(framerate),  texture_(texture),  frame_(frame)
    {
        this->setTexture(texture_);
        this->addAnimation(length);
    }
    void addAnimation(const int length){
        {
            startRect = sf::IntRect(frame_.top * frame_.width,
                                          frame_.top * frame_.height,
                                          frame_.width,
                                          frame_.height);

            currentRect = startRect;

            endRect = sf::IntRect(frame_.top * frame_.width + frame_.width * (length - 1),
                                        (frame_.top) * frame_.height,
                                        frame_.width,
                                        frame_.height);

            this->setTextureRect(startRect);
        }
    };
    void playAnimation(const float &dt){
        this->timer += dt;

        if (this->timer > 1 / framerate_)
        {
            this->timer = 0.f;

            if (currentRect != endRect)
            {
                currentRect.left += frame_.width;
            }
            else
            {
                currentRect = startRect;
            }
            this->setTextureRect(currentRect);
        }
    };

private:
    float framerate_ = 0.f;
    sf::Texture texture_;
    std::vector<sf::IntRect> frames;
    sf::IntRect frame_;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
    float timer = 0.f;
};


#endif // ANIMATION_H
