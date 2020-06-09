#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "object.h"
#include "player.h"
#include "enemy.h"
#include "coin.h"
class Game;
class ObjectManager
{
private:
    float points;
    double x = 0.f;
    double y = 10.f;
    void add(const int &m,const int &n,std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color);
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
public:
    const std::map<int , std::map<int, std::unique_ptr<Object>>> &getBoard(){
        return board_;
    }
    void Paint(const Player &gracz);
    void Paint(const sf::RenderWindow &window, const sf::Event &event);
    void Paint(const Enemy &enemy);
    bool full_board();
    ObjectManager(const sf::Texture &texture);
    virtual ~ObjectManager() = default;
};

#endif // OBJECTMANAGER_H
