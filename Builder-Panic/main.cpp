
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
    if (!wall_texture.loadFromFile("/home/maciek/work/tekstury/teksturki/wall.png")) {
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
                if(game.event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(game.window_);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
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
        game.window_.draw(gracz);
        game.window_.display();
    }
    return 0;
}
