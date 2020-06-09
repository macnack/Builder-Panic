#ifndef ANIMATION_H
#define ANIMATION_H
#include "player.h"

class AnimatedSprite : public sf::Sprite{
public:
    AnimatedSprite(){};
    virtual ~AnimatedSprite(){}
    void add_animation_frame(const sf::IntRect &frame);
    void step(const sf::Time &elapsed);
    float show_framerate(){return framerate;}
    void jump();
    void animate(const sf::Time &elapsed, const std::vector<sf::Sprite> &platform);
    //void collisions(const std::vector<sf::Sprite> &platforms, const sf::Time &elapsed);
    void rotate();
private:
    std::vector<sf::IntRect> frames;
    bool rotated = false;
    bool grounded = false;
    float time = 0;
    float framerate;

    float velocity_x = 0;
    float velocity_y = 0;
    float h = 0.06f;
    float acceleration_x = 0.1f;
    float deceleration_x = acceleration_x * 0.55f;
    float acceleration_y = 0.981f;

};

#endif // ANIMATION_H
