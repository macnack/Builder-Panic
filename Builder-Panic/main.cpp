
#include "game.h"
#include "object.h"
#include "wall.h"
using namespace std;
int main()
{
    float maxHeight = 610.0f;//600
    float maxWidth = 800.0f;//800
    Game game(maxWidth,maxHeight);
    sf::Texture wall_texture;
    if (!wall_texture.loadFromFile("Texture/wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    wall_texture.setRepeated(true);
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
    for(double i = 91.25 ; i <= 800; i += 101.25){ //wall
        std::unique_ptr<sf::Sprite> wall = std::make_unique<Object>
                (sf::Vector2f(i,0), sf::IntRect(0,0,10.0,800.0));
        wall->setTexture(wall_texture);
        map["walls"].emplace_back(std::move(wall));
    }
    for(int i = 0 ; i <= 600; i += 150){ //floor
        std::unique_ptr<sf::Sprite> floor = std::make_unique<Object>
                (sf::Vector2f(0,i), sf::IntRect(0,0,800.0,10.0));
        floor->setTexture(wall_texture);
        map["floors"].emplace_back(std::move(floor));
    }
    std::vector<unique_ptr<sf::RectangleShape>> blocks;
    for(double i = 0; i <= 800; i += 101.25){
        for (double j  = 10.0 ; j <= 610.0; j += 150){
            std::unique_ptr<sf::RectangleShape> block = std::make_unique<sf::RectangleShape>(sf::Vector2f(91.25,140));
            block->setPosition(i,j);
            block->setFillColor(sf::Color(128,128,128));
            blocks.emplace_back(std::move(block));
        }
    }
    Player gracz(sf::Vector2f(50,100),sf::Vector2f(100,480));
    while (game.getWindow().isOpen())
    {
        sf::Time elapsed = game.clock_.restart();
        while (game.window_.pollEvent(game.event))
        {
            if (game.event.type == sf::Event::Closed)
            {
                game.window_.close();
            }
            if (game.event.type == sf::Event::MouseButtonPressed) {

                sf::Vector2i mouse_pos = sf::Mouse::getPosition(game.window_);
                //std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                for(auto &bl : blocks){
                    if(bl->getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                        if(game.event.mouseButton.button == sf::Mouse::Left){
                            bl->setFillColor(sf::Color(0,0,0));
                        }
                        if(game.event.mouseButton.button == sf::Mouse::Right){
                            bl->setFillColor(sf::Color(255,255,255));
                        }
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            for(auto &bl :blocks){
                bl->setFillColor(sf::Color(124,124,124));
            }
        }
        gracz.move(elapsed);
        game.window_.clear(sf::Color::Black);

        for(const auto &wl: map["walls"]){
            game.window_.draw(*wl);
        }
        for(const auto &fl: map["floors"]){
            game.window_.draw(*fl);
        }
        for(const auto &bl: blocks){
            game.window_.draw(*bl);
        }
        game.window_.draw(gracz);
        game.window_.display();
    }
    return 0;
}
