#include "game.h"

void Game::draw()
{
    scena.draw();
    obj_manager->draw();
    for (const auto &c : coins)
    {
        window_.draw(*c);
    }
    window_.draw(*gracz);
    window_.draw(*enemy);
}
void Game::run()
{
    //game loop
    sf::View view( gracz->view(), sf::Vector2f(800,600));
    while (window_.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Time elapsed = clock_.restart();
        while (window_.pollEvent(event))
        {
            view.setCenter(gracz->view());
            window_.setView(view);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                obj_manager->Paint(window_, event);
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                { // reset plansz
                    obj_manager.reset();
                    obj_manager = std::make_unique<ObjectManager>(&window_);
                }
            }
            if (obj_manager->full_board())
            {
                std::cerr << "Press R to reset" << std::endl;
                sf::sleep(sf::microseconds(1000));
                window_.close();
                obj_manager->addScore(*gracz, *enemy);
                std::cerr << "Wynik dla gracza 1: " << gracz->getScore() << std::endl;
                std::cerr << "Wynik dla gracza 2: " << enemy->getScore() << std::endl;
            }
        }
        for (auto it = coins.begin(); it < coins.end(); it++)
        {
            (*it)->loop(scena.getVec("floors"), elapsed.asSeconds());
            if ((*it)->is_collected(*gracz,*enemy))
            {
                coins.erase(it);
                std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
                coins.push_back(std::move(coin));
            }
        }
        obj_manager->Paint(*gracz);
        obj_manager->Paint(*enemy);
        gracz->getHurt(*enemy, elapsed.asSeconds());
        enemy->getHurt(*gracz, elapsed.asSeconds());
        enemy->loop(scena.getVec("floors"), elapsed.asSeconds());
        gracz->loop(scena.getVec("floors"), elapsed.asSeconds());
        window_.clear(sf::Color::Black);

        this->draw();

        window_.display();
    }
}

Game::Game(const float &w, const float &h) : window_(sf::VideoMode(w, h), "Bulding Panic"), scena(&window_)
{
    obj_manager = std::make_unique<ObjectManager>(&window_);
    gracz = std::make_unique<Player>(sf::Vector2f(100, 250));
    enemy = std::make_unique<Enemy>(sf::Vector2f(100, 250));
    for (int i = 0; i < 3; i++)
    {
        std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
        coins.push_back(std::move(coin));
    }
}
