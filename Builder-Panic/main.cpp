
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
    std::map<int , std::map<int, std::unique_ptr<Object>>> board;
    for(int i = 0 ; i < 8; i++){
        for(int k =0; k < 4; k++){
            std::unique_ptr<Object> block_ = std::make_unique<Object>
                    (sf::Vector2f(x,y),sf::FloatRect(0,0,91.25,140),wall_texture);
            board.insert(make_pair(k, std::map<int,std::unique_ptr<Object>>()));
            board[k].insert(make_pair(i, std::move(block_)));
            y += 150;
        }
        x += 101.25;
        y = 10.0;
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
                for(auto &bd : board){
                    int m = bd.first;
                    for(auto &bd_el : bd.second){
                    if(bd_el.second->getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                        if(game.event.mouseButton.button == sf::Mouse::Left){
                            std::cerr << m << " " <<bd_el.first << std::endl;
                            bd_el.second->Paint(Object::Color::Player);
                        }
                        if(game.event.mouseButton.button == sf::Mouse::Right){
                            bd_el.second->Paint(Object::Color::Enemy);
                        }
                    }
                }
            }
        } }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            for(auto &bd : board){
                for(auto &bd_el : bd.second){
                    bd_el.second->setColor(sf::Color(128,128,128));
                }
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
        for(const auto &el : board){
            for(const auto &v : el.second){
                game.window_.draw(*v.second);
            }
        }
        game.window_.draw(gracz);
        game.window_.display();
    }
    return 0;
}
