#include "game.h"

void Game::draw()
{
    scena.draw();
    obj_manager->draw();
    for (const auto &c : coins)
    {
        window_.draw(*c);
    }
    window_.draw(*gracz); //gracz->draw()
    window_.draw(*enemy); //-||-
}
void Game::run()
{
    //game loop
    while (window_.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Time elapsed = clock_.restart();
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                obj_manager->Paint(window_, event);
            }
            if (event.type == sf::Event::KeyPressed)
            {
                gracz->change_platform();
                enemy->change_platform();
                obj_manager->Paint(*gracz);
                obj_manager->Paint(*enemy);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                { // reset plansz
                    obj_manager.reset();
                    obj_manager = std::make_unique<ObjectManager>(&window_);
                }
            }
            if (obj_manager->full_board())
            {
                sf::sleep(sf::microseconds(10000));
                std::cerr << "Press R to reset" << std::endl;
            }
        }
        for (auto it = coins.begin(); it < coins.end(); it++)
        {
            (*it)->playAnimation(elapsed.asSeconds());
            (*it)->updateCollisions(scena.getVec("floors"), elapsed.asSeconds());
            if ((*it)->is_collected(*gracz) || (*it)->is_collected(*enemy))
            {
                coins.erase(it);
                std::unique_ptr<Coin> coin = std::make_unique<Coin>();
                coins.push_back(std::move(coin));
            }
        }

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
    //sf::Texture hero_texture;
    //    if (!hero_texture.loadFromFile("Texture/engineer character/engineer.png"))
    //    {
    //        throw("Could not load texture 'Engineer Idle'");
    //    }
    sf::Texture run_texture;
    if (!run_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
    {
        throw("Could not load texture 'Engineer Idle'");
    }
    //Animation idles(hero_texture, sf::IntRect(0,0,16,28), 7, 4);
    //          run(..., sf::IntRect(0, 0, 16, 28), 12, 8)
    gracz = std::make_unique<Player>(sf::Vector2f(100, 250),14);
    enemy = std::make_unique<Enemy>(sf::Vector2f(100, 250),14);
    for (int x = 160; x <= 460; x += 150)
    {
        std::unique_ptr<Coin> coin = std::make_unique<Coin>(sf::Vector2f(x, 350));
        coins.push_back(std::move(coin));
    }
}
