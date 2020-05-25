
#include "game.h"
#include "object.h"

using namespace std;
int main()
{
    float maxHeight = 610.0f;//600
    float maxWidth = 795.0f;//800
    Game game(maxWidth,maxHeight);
    std::map<std::string, std::vector<std::unique_ptr<sf::RectangleShape>>> map;
    double x = 95;
    for(int i = 0 ; i < 7; i++){ //wall
        std::unique_ptr<sf::RectangleShape> wall = std::make_unique<sf::RectangleShape>();
        wall->setSize(sf::Vector2f(5.0, 800.0));
        wall->setPosition(x,0);
        wall->setFillColor(sf::Color(124, 124, 250));
        map["walls"].emplace_back(std::move(wall));
        x += 100;
    }
    double y = 0;
    for(int i = 0 ; i < 5; i++){ //floor
        std::unique_ptr<sf::RectangleShape> floor = std::make_unique<sf::RectangleShape>();
        floor->setSize(sf::Vector2f(800.0, 10.0));
        floor->setPosition(0,y);
        floor->setFillColor(sf::Color(124, 124, 250));
        map["floors"].emplace_back(std::move(floor));
        y += 150;
    }
    std::vector<sf::RectangleShape> scianka;
    //sf::RectangleShape
    sf::Vector2f pos(457,480);
    sf::Vector2f size(50, 100);
    Player gracz(size,pos);
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
