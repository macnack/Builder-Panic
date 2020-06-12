#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

//class Enemy : public Entity
//{
//public:
//    Enemy(const sf::Vector2f &pos) : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 9, 8, 2) //docelowy konstruktor
//    {
//        grounded = true;
//        rando = rand() % 3 - 1;
//    }
//    Enemy(const sf::Vector2f &pos, const int &framerate)
//        : Entity(pos, sf::IntRect(0, 0, 16, 28), framerate)
//    {
//        grounded = true;
//    }
//    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
//    void change_platform();
//    virtual ~Enemy() = default;
//private:
//    int rando;
//};

#endif // ENEMY_H
