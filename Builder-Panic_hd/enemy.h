#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

class Enemy : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    Enemy(const sf::Vector2f &pos) : Hero(pos)
    {
        this->setColor(Object::Color::Enemy);
    }
    virtual ~Enemy() = default;

private:
    bool painting();
    bool left_move();
    bool right_move();
    bool jump_move();
    bool down_move();
    bool charge_move();
};


#endif // ENEMY_H
