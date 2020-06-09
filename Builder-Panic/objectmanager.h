#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "object.h"
#include "player.h"
#include "enemy.h"

class Game;
class ObjectManager
{
private:
    float points;
public:
    void add(const int &m,const int &n,std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color);
    void Paint(const sf::RenderWindow &window, const sf::Event &event);
    void Paint(const Player &gracz);
    void Paint(const Enemy &enemy);
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
    bool full_board();
    ObjectManager(){}
    virtual ~ObjectManager() = default;
};

#endif // OBJECTMANAGER_H
