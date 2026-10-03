#ifndef GAME_H
#define GAME_H
#include "menu.h"
#include "smartenemy.h"
class Game : public sf::RenderWindow
{
public:
    int run(int smoke_frames = 0);
    Game(const float &w, const float &h);
    virtual ~Game() = default;

private:
    sf::RenderWindow window_;
    sf::SoundBuffer buffer;
    sf::Sound coin_effect;
    bool coin_sound_ = false;
    Scena scena;
    Menu menu;
    float timer = 0.f;
    void draw();
    void update(const float &dt);
    void restart();
    void ensure_lobby_coins();
    sf::Event event;
    sf::Clock clock;
    std::unique_ptr<SmartEnemy> enemy;
    std::unique_ptr<Player> gracz;
    std::vector<std::unique_ptr<Coin>> coins;
    std::unique_ptr<ObjectManager> obj_manager;
};

#endif // GAME_H
