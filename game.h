#ifndef GAME_H
#define GAME_H
#pragma once
#include "player.h"

class Game : public sf::RenderWindow
{
public:
    void run();
    void draw();
    void update();
    Game(const float &w, const float &h);
    virtual ~Game(){};
    const sf::RenderWindow &getWindow();
    const sf::Clock &getClock();
    const sf::Event &getEvent();
    sf::RenderWindow window_; //to private
    sf::Event event; //to private
    sf::Clock clock_; // to private
private:
    Player gracz;
    std::string title;
    float width_;
    float height_;
};

#endif // GAME_H
