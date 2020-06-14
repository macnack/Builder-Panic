#ifndef SMARTENEMY_H
#define SMARTENEMY_H

#include "enemy.h"

//klasa prowizorka
class SmartEnemy : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void change_platform();
    bool painting();
    virtual ~SmartEnemy() = default;
    SmartEnemy(const sf::Vector2f &pos) : Hero(pos)
    {
        this->setColor_flag(Object::Color::Enemy);
    }

private:
    void attack_move();
    void down();
    void jump();
};

#endif // SMARTENEMY_H
