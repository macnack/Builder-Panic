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
    menu.Draw();
}

void Game::update(const float &dt)
{
    if (obj_manager->full_board())
    {
        std::cerr << "Press R to reset" << std::endl;
        sf::sleep(sf::microseconds(1000));
        obj_manager->addScore(*gracz, *enemy);
        std::cerr << "Wynik dla gracza 1: " << gracz->getScore() << std::endl;
        std::cerr << "Wynik dla gracza 2: " << enemy->getScore() << std::endl;
    }
    for (auto it = coins.begin(); it < coins.end(); it++)
    {
        (*it)->loop(scena.getVec("floors"), dt);
        if ((*it)->is_collected(*gracz,*enemy))
        {
            coins.erase(it);
            std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
            coins.push_back(std::move(coin));
        }
    }
    if(menu.paused() == false)
    {
        obj_manager->Paint(*gracz);
        obj_manager->Paint(*enemy);
        gracz->getHurt(*enemy, dt);
        enemy->getHurt(*gracz, dt);
        enemy->loop(scena.getVec("floors"), dt);
        gracz->loop(scena.getVec("floors"), dt);
    }
}
void Game::run()
{
    //game loop
    //    sf::View view( gracz->view(), sf::Vector2f(800,600));
    for (int i = 0; i < 3; i++)
    {
        std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
        coins.push_back(std::move(coin));
    }
    while (window_.isOpen())
    {
        sf::Time elapsed = clock_.restart();
        //        view.setCenter(gracz->view());
        //        window_.setView(view);

        // check all the window's events that were triggered since the last iteration of the loop
        while (window_.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window_.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                { // reset plansz
                    obj_manager.reset();
                    obj_manager = std::make_unique<ObjectManager>(&window_);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    std::cerr << gracz->getScore() << std::endl;
                    std::cerr << enemy->getScore() << std::endl;
                }
            }
            menu.menu_event(event,*gracz,*enemy);
            if(menu.restared() )
            {
                obj_manager.reset();
                obj_manager = std::make_unique<ObjectManager>(&window_);
            }
        }
        this->update(elapsed.asSeconds());
        window_.clear(sf::Color::Black);
        this->draw();
        window_.display();
    }
}

Game::Game(const float &w, const float &h)
    : window_(sf::VideoMode(w, h), "Bulding Panic"), scena(&window_), menu(&window_)
{
    obj_manager = std::make_unique<ObjectManager>(&window_);
    gracz = std::make_unique<Player>();
    enemy = std::make_unique<Enemy>();
}
