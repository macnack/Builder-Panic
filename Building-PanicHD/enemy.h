#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

class Enemy : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    Enemy();
    Enemy(const sf::Vector2f &pos);
    virtual ~Enemy() = default;

private:
    bool painting();
    bool left_move();
    bool right_move();
    bool jump_move();
    bool down_move();
    bool charge_move();
    void change_platform();
};


#endif // ENEMY_H
