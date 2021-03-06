#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobject.h"

class Animation : public sf::Sprite
{
public:
    std::vector<sf::IntRect> addAnimation(const sf::IntRect &frame, const int &length);
    void playAnimation(const float &dt);
    Animation(const sf::IntRect &frame,
              const float &framerate, const int &length);
    Animation(const sf::IntRect &frame,
              const float &framerate);
    virtual ~Animation() = default;

private:
    float framerate_ = 0.f;
    float timer = 0.f;

protected:
    bool faceRight = true;
    int switcher = 0;
    sf::IntRect frame_;
    std::vector<sf::Texture> textures_;
    std::vector<std::vector<sf::IntRect>> frames_;
};

#endif // ANIMATION_H
