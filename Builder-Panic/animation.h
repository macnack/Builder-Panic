#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobject.h"
//bosz ale bajzel
class Animation : public sf::Sprite
{
public:
    Animation(const sf::Vector2f &pos, const sf::Texture &texture,
              const sf::IntRect &frame,
              const float &framerate, const int &length);
    Animation(const sf::Texture &texture,
              const sf::IntRect &frame,
              const float &framerate, const int &length);
    Animation(const sf::IntRect &frame,
              const float &framerate, const int &length);
    virtual ~Animation() = default;
    std::vector<sf::IntRect> addAnimation(const sf::IntRect &frame,const int length);
    void playAnimation(const float &dt){
        timer += dt;
        if (timer > 1 / framerate_)
        {
            timer = 0.f;
            if (frames_[switcher][1] != frames_[switcher][2])
            {
                frames_[switcher][1].left += frames_[switcher][0].width;
            }
            else
            {
                frames_[switcher][1] = frames_[switcher][0];
            }
            this->setTextureRect(frames_[switcher][1]);
        }
    }


private:
    float framerate_ = 0.f;
    float timer = 0.f;

protected:
    sf::IntRect frame_;
    sf::Texture texture_;
    std::vector<sf::Texture> textures_;
    std::vector<std::vector<sf::IntRect>> frames_;
    int switcher = 0;

};


#endif // ANIMATION_H
