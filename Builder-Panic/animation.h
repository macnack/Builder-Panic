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
    void addAnimation(const sf::IntRect &frame,const int length);
    void addAnimation_moves(const sf::Texture &texture,const sf::IntRect &frame, const int &length){
        move_texture = texture;
        for( int i = frame.left ; i <= frame.width * length; i += frame.width){
            move_frames.push_back(sf::IntRect(i,frame.top,frame.width,frame.height));
        }
    }
    void addAnimation_jump(const sf::Texture &texture,const sf::IntRect &frame, const int &length){
        jump_texture = texture;
        for( int i = frame.left ; i < frame.width * length; i += frame.width){
            jump_frames.push_back(sf::IntRect(i,frame.top,frame.width,frame.height));
        }
    }
    std::vector<sf::IntRect> addAnimation_frame(const sf::IntRect &frame, const int &length);//rm
    void playAnimation(const float &dt){
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

private:
    float framerate_ = 0.f;
    sf::Texture texture_;
    sf::Texture move_texture;
    sf::Texture jump_texture;
    sf::IntRect frame_;
    std::vector<sf::IntRect> move_frames;
    std::vector<sf::IntRect> jump_frames;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
    float timer = 0.f;
};


#endif // ANIMATION_H
