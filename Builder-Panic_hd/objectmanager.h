#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "enemy.h"

class ObjectManager
{
public:
    bool full_board();
    const std::map<int, std::map<int, std::unique_ptr<Object>>> &getBoard();
    void draw();
//    void Paint(Player &gracz);
//    void Paint(Enemy &enemy);
    void Paint(Hero &hero);
    void Paint(const sf::RenderWindow &window, const sf::Event &event); //inspekt
    void addScore(Player &gracz, Enemy &enemy);
    ObjectManager(sf::RenderWindow *window);
    virtual ~ObjectManager() = default;

private:
    double x = 0.;
    double y = 25.0;
    int rows = 4;
    int columns = 8;
    float points;
    void add(const int &m, const int &n, std::unique_ptr<Object> block_);
    void Reverse(const int &m, const int &n, const Object::Color &color);
    sf::RenderWindow *window_;
    sf::Texture texture;
    std::map<int, std::map<int, std::unique_ptr<Object>>> board_;
};

#endif // OBJECTMANAGER_H
