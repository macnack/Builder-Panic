#ifndef GAME_H
#define GAME_H
#include "menu.h"
class Game : public sf::RenderWindow
{
public:
    void run();
    Game(const float &w, const float &h);
    virtual ~Game() = default;

private:
    sf::RenderWindow window_;
    sf::SoundBuffer buffer;
    sf::Sound coin_effect;
    Scena scena;
    Menu menu;
    float timer = 0.f;
    void draw();
    void update(const float &dt);
    void restart();
    sf::Event event;
    sf::Clock clock;
    std::unique_ptr<Enemy> enemy;
    std::unique_ptr<Player> gracz;
    std::vector<std::unique_ptr<Coin>> coins;
    std::unique_ptr<ObjectManager> obj_manager;
};

#endif // GAME_H
