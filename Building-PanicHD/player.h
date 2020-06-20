#ifndef PLAYER_H
#define PLAYER_H

#include "coin.h"

class Player : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    Player();
    Player(const sf::Vector2f &pos);
    virtual ~Player() = default;

private:
    bool painting();
    bool left_move();
    bool right_move();
    bool jump_move();
    bool down_move();
    bool charge_move();
    void change_platform();
};

#endif // PLAYER_H
