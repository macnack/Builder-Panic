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
    void playAnimation(const float &dt);
    void playAnimation_idle(const float &dt){
        timer += dt;
        for(unsigned int i = 0; i < move_frames.size(); i++){
            if( timer > 1.0f){
                timer = 0.0f;
            }
            if(timer >= i- move_frames.size()/10.0*i){
                this->setTextureRect(move_frames[i]);
            }
        }
    }
    void playAnimation_move(const float &dt){
        timer += dt;
        for(unsigned int i = 0; i < move_frames.size(); i++){
            if( timer > 1.0f){
                timer = 0.0f;
            }
            if(timer >= i- move_frames.size()/10.0*i){
                this->setTextureRect(move_frames[i]);
            }
            if(timer > move_frames.size()/10.0){
                timer = 0.3f;
            }
        }
    }
    void playAnimation_jump(const float &dt){
        timer += dt;
        this->setTexture(jump_texture);
        for(unsigned int i = 0; i < jump_frames.size(); i++){
            if( timer > 1.0f){
                timer = 0.0f;
            }
            if(timer >= i- jump_frames.size()/10.0*i){
                this->setTextureRect(jump_frames[i]);
            }
            if(timer > jump_frames.size()/10.0){
                timer = 0.3f;
            }
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
