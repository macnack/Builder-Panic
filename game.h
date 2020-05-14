#ifndef GAME_H
#define GAME_H
#pragma once
#include "player.h"
class Game : public sf::RenderWindow
{
public:

    Game();
    virtual ~Game();
    void run();
private:
    Player gracz;
    static float width;
    static float height;
    static sf::RenderWindow window;
    static std::string name;
    static sf::Clock clock;
    static sf::Event event;
    void render();
    void update();
    void makeWindow();
    const sf::RenderWindow& Window() const;
};

#endif // GAME_H
