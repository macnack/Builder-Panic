#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"


class Player : public Entity{
public:
    Player(const sf::Vector2f &size, const sf::Vector2f &pos) : Entity(size, pos){
        grounded = true;
    }
    void loop(const  std::vector<std::unique_ptr<sf::Sprite>> &platforms ,const float& dt);
    void change_platform();
private:

};


#endif // PLAYER_H
