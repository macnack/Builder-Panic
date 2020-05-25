#include "game.h"


void Game::draw()
{
    //draw here
}
void Game::run()
{
    //game loop
    while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();
            }
            window_.clear(sf::Color::Black);

            this->draw();

            window_.display();
    }
}

Game::Game(const float &w, const float &h): window_(sf::VideoMode(w,h),"Bulding Panic")
{
        Player player;
        sf::Clock clock;
        clock_ = clock;

}

const sf::RenderWindow &Game::getWindow()
{
    return window_;
}

const sf::Clock &Game::getClock()
{
    return clock_;
}

const sf::Event &Game::getEvent()
{
    return event;
}
