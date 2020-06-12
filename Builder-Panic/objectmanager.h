#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "enemy.h"

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
    void addScore(Player &gracz, Enemy &enemy){
        for (const auto &el : board_)
        {

            for (const auto &v : el.second)
            {
                if (v.second->getColor() == gracz.getColor() )
                {
                    gracz.addScore(150);
                }
                if (v.second->getColor() == gracz.getColor() )
                {
                    enemy.addScore(150);
                }
            }
        }
    }
    const std::map<int, std::map<int, std::unique_ptr<Object>>> &getBoard();
    void Paint(Player &gracz);
    void Paint(Enemy &enemy);
    void Paint(const sf::RenderWindow &window, const sf::Event &event); //inspekt
    bool full_board();
    void draw();
    ObjectManager(sf::RenderWindow *window);
    virtual ~ObjectManager() = default;

};

#endif // OBJECTMANAGER_H
