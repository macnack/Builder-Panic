#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"


class Player : public Entity{
public:
    Player(const sf::Vector2f &pos, const sf::Texture &texture,
           const sf::IntRect &frame, const float &framerate,
           const int &length): Entity(pos, texture,frame,framerate, length){
        grounded = true;
        std::cerr << "x: "<<this->getScale().x << " y: " << this->getScale().y << std::endl;
        //this->setOrigin(getLocalBounds().width/2,0);
    }
    void loop(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms ,const float& dt);
    void change_platform();
private:

};


#endif // PLAYER_H
