#ifndef GAME_H
#define GAME_H
#include "menu.h"
class Game : public sf::RenderWindow
{
public:
    friend class Menu;
    void run();
    void draw();
    void update(const float &dt);
    Game(const float &w, const float &h);
    virtual ~Game() = default;

private:
    sf::RenderWindow window_;
    float height_;
    float width_;
    Scena scena;
    Menu menu;
    std::string title;
    std::unique_ptr<Enemy> enemy;
    std::unique_ptr<Player> gracz;
    std::unique_ptr<ObjectManager> obj_manager;
    std::vector<std::unique_ptr<Coin>> coins;
    sf::Clock clock_;
    sf::Event event;
};

#endif // GAME_H
