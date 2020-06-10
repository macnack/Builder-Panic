#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobject.h"

class Animation : public sf::Sprite
{
public:
    Animation(const sf::Vector2f &pos, const sf::Texture &texture,
         const sf::IntRect &frame,
              const float &framerate, const int &length);
    Animation(const sf::Texture &texture,
         const sf::IntRect &frame,
         const float &framerate, const int &length);
    void addAnimation(const sf::IntRect &frame,const int length);;
    std::vector<sf::IntRect> addAnimation_frame(const sf::IntRect &frame, const int &length);//rm
    void playAnimation(const float &dt);

private:
    float framerate_ = 0.f;
    sf::Texture texture_;
    sf::IntRect frame_;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
    float timer = 0.f;
};


#endif // ANIMATION_H
