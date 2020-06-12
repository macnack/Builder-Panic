#ifndef GAME_H
#define GAME_H
#include "scena.h"
class Game : public sf::RenderWindow
{
public:
    void run();
    void draw();
    void update();
    Game(const float &w, const float &h);
    virtual ~Game() = default;

private:
    sf::RenderWindow window_;
    sf::Event event;
    sf::Clock clock_;
    Scena scena;
    std::unique_ptr<Enemy> enemy;
    std::unique_ptr<Hero> gracz;
    std::unique_ptr<ObjectManager> obj_manager;
    std::vector<std::unique_ptr<Coin>> coins;
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
    std::string title;
    float width_;
    float height_;
};

#endif // GAME_H
