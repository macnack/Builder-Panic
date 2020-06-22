#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "enemy.h"

class ObjectManager
{
public:
    bool full_board();
    const std::map<int, std::map<int, std::unique_ptr<Object>>> &getBoard();
    void draw();
    void Paint(Hero &hero);
    void Paint(const sf::RenderWindow &window, const sf::Event &event); //moudr inspekt
    void addScore(Player &gracz, Enemy &enemy);
    ObjectManager(sf::RenderWindow *window);
    virtual ~ObjectManager() = default;

private:
    bool end_game = false;
    double x = 65.25;
    double y = 25.0;
    int rows = 4;
    int columns = 8;
    float points;
    void add(const int &m, const int &n, std::unique_ptr<Object> block_);
    void Reverse(const int &m, const int &n, const Object::Color &color);
    sf::RenderWindow *window_;
    sf::Texture texture;
    sf::SoundBuffer buffer;
    sf::Sound painting_effect;
    std::map<int, std::map<int, std::unique_ptr<Object>>> board_;
};

#endif // OBJECTMANAGER_H
