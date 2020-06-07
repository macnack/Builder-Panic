#include "game.h"


void Game::draw()
{
    //draw here
    for(const auto &wl: map["walls"]){
        window_.draw(*wl);
    }
    for(const auto &fl: map["floors"]){
        window_.draw(*fl);
    }
    for(const auto &el : obj_manager.board_){
        for(const auto &v : el.second){
            window_.draw(*v.second);
        }
    }
    window_.draw(*gracz);
}
void Game::run()
{
    //game loop
    while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Time elapsed = clock_.restart();
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();
                if (event.type == sf::Event::MouseButtonPressed) {
                    obj_manager.Paint(window_, event);
                }
                if (event.type == sf::Event::KeyPressed){
                    gracz->change_platform();
                }
            }
            obj_manager.Paint(*gracz);
            gracz->loop(map["floors"], elapsed.asSeconds());
            if(obj_manager.full_board()){
                std::cerr << "koniec" << std::endl;
            }
            window_.clear(sf::Color::Black);
            this->draw();

            window_.display();
    }
}

Game::Game(const float &w, const float &h): window_(sf::VideoMode(w,h),"Bulding Panic")
{
        sf::Clock clock;
        clock_ = clock;
        sf::Texture wall_texture;
        if (!wall_texture.loadFromFile("Texture/wall.png")) {
            std::cerr << "Could not load texture" << std::endl;
            throw 1;
        }    wall_texture.setRepeated(true);
        for(double i = 91.25 ; i <= 800; i += 101.25){ //wall
            std::unique_ptr<sf::Sprite> wall = std::make_unique<Object>
                    (sf::Vector2f(i,0), sf::FloatRect(0,0,10.0,800.0),wall_texture);
            wall->setColor(sf::Color(255,0,0));
            map["walls"].emplace_back(std::move(wall));
        }
        for(int i = 0 ; i <= 600; i += 150){ //floor
            std::unique_ptr<sf::Sprite> floor = std::make_unique<Object>
                    (sf::Vector2f(0,i), sf::FloatRect(0,0,800.0,10.0),wall_texture);
            floor->setColor(sf::Color(255,0,0));
            map["floors"].emplace_back(std::move(floor));
        }
        double x = 0.f;
        double y = 10.f;
        for(int i = 0 ; i < 8; i++){
            for(int k =0; k < 4; k++){
                std::unique_ptr<Object> block_ = std::make_unique<Object>
                        (sf::Vector2f(x,y),sf::FloatRect(0,0,91.25,140),wall_texture);
                obj_manager.add(k,i,std::move(block_));
                y += 150;
            }
            x += 101.25;
            y = 10.0;
        }
        gracz = new Player(sf::Vector2f(50,100),sf::Vector2f(100,250));
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
