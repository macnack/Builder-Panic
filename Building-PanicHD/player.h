#ifndef PLAYER_H
#define PLAYER_H

#include "coin.h"

class Player : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    Player();
    Player(const sf::Vector2f &pos);
    virtual ~Player() = default;

private:
    sf::Vector2f pos_ = sf::Vector2f(825, 250);
    bool painting();
    bool left_move();
    bool right_move();
    bool jump_move();
    bool down_move();
    bool charge_move();
};

#endif // PLAYER_H
