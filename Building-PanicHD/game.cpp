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
    if(!menu.paused())
    {
        obj_manager->Paint(*gracz);
        obj_manager->Paint(*enemy);
        gracz->getHurt(*enemy, dt);
        enemy->getHurt(*gracz, dt);
        enemy->loop(scena.getVec("floors"), dt);
        gracz->loop(scena.getVec("floors"), dt);
    }
    if( menu.game_mode() )
    {
        timer += dt;
        if( timer > 5.f )
        {
            if(coins.size() < 4)
            {
                std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
                coins.push_back(std::move(coin));
            }
            timer = 0.f;
        }
    }
    for (auto it = coins.begin(); it < coins.end(); it++)
    {
        (*it)->loop(scena.getVec("floors"), dt);
        if ((*it)->is_collected(*gracz,*enemy))
        {
            coins.erase(it);
            coin_effect.play();
            if ( menu.lobbie_mode() )
            {
                std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
                coins.push_back(std::move(coin));
            }
        }
    }
}

void Game::restart()
{
    if ( menu.lobbie_mode() )
    {
        while ( coins.size() < 10)
        {
            std::unique_ptr<Coin> coin = std::make_unique<Coin>(scena.getVec("floors"));
            coins.push_back(std::move(coin));
        }
    }
    if( menu.restarted() )
    {
        coins.clear();
        obj_manager.reset();
        obj_manager = std::make_unique<ObjectManager>(&window_);
        sf::milliseconds(10);
        gracz->resetScore();
        enemy->resetScore();
        menu.reset();
    }
}
void Game::run()
{
    //game loop
    //    sf::View view( gracz->view(), sf::Vector2f(800,600));
    sf::Music music;
    if (!music.openFromFile("Audio/muzyczka.wav")){
        throw("sound.wav");
    }
    music.setLoop(true);
    music.setVolume(30);
    music.play();
    while (window_.isOpen())
    {
        sf::Time elapsed = clock.restart();
        //        view.setCenter(gracz->view());
        //        window_.setView(view);

        // check all the window's events that were triggered since the last iteration of the loop
        while (window_.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window_.close();
            }
            if( obj_manager->full_board() )
            {
                obj_manager->addScore(*gracz,*enemy);
                menu.end_update(*gracz,*enemy);
            }
            menu.menu_event(event,*gracz,*enemy);
            this->restart();

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
    if (!buffer.loadFromFile("Audio/coins.wav"))
        throw("sound wav");
    coin_effect.setBuffer(buffer);
}
