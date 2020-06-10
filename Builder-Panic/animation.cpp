#include "animation.h"


Animation::Animation(const sf::Vector2f &pos, const sf::Texture &texture,
                     const sf::IntRect &frame, const float &framerate, const int &length)
    : framerate_(framerate),  texture_(texture)
{
    this->setPosition(pos);
    this->setTexture(texture_);
    this->addAnimation(frame,length);

}

Animation::Animation(const sf::Texture &texture, const sf::IntRect &frame,
                     const float &framerate, const int &length)
    : framerate_(framerate),  texture_(texture)
{
    this->setTexture(texture_);
    this->addAnimation(frame,length);
}

void Animation::addAnimation(const sf::IntRect &frame , const int length){
    {
        startRect = sf::IntRect(frame.top * frame.width,
                                frame.top * frame.height,
                                frame.width,
                                frame.height);
        currentRect = startRect;
        endRect = sf::IntRect(frame.top * frame.width + frame.width * (length - 1),
                              frame.top * frame.height,
                              frame.width,
                              frame.height);
        this->setTextureRect(startRect);
    }
}

std::vector<sf::IntRect> Animation::addAnimation_frame(const sf::IntRect &frame, const int &length){
    std::vector<sf::IntRect> tmp;
    for( int i = frame.left ; i <= frame.width * length; i += frame.width){
        tmp.push_back(sf::IntRect(i,frame.top,frame.width,frame.height));
    };
    return tmp;
}

void Animation::playAnimation(const float &dt){
    timer += dt;
    if (timer > 1 / framerate_)
    {
        timer = 0.f;
        if (currentRect != endRect)
        {
            currentRect.left += startRect.width;
        }
        else
        {
            currentRect = startRect;
        }
        this->setTextureRect(currentRect);
    }
}
