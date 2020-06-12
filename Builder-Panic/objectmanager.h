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
    int columns = 8;
    int rows = 4;
    double x = 0.f;
    double y = 10.f;
    sf::Texture texture;
    sf::RenderWindow *window_;
    void add(const int &m, const int &n, std::unique_ptr<Object> block_);
    void Reverse(const int &m, const int &n, const Object::Color &color);
    std::map<int, std::map<int, std::unique_ptr<Object>>> board_;

public:
    const std::map<int, std::map<int, std::unique_ptr<Object>>> &getBoard();
    void Paint(const Player &gracz);
    void Paint(const sf::RenderWindow &window, const sf::Event &event); //inspekt
    //void Paint(const Enemy &enemy);
    bool full_board();
    void draw();
    ObjectManager(sf::RenderWindow *window);
    virtual ~ObjectManager() = default;

};

#endif // OBJECTMANAGER_H
