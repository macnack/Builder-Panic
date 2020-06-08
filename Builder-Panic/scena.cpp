#include "scena.h"

Scena::Scena(sf::Texture &wall_texture){
    wall_texture.setRepeated(true);
    for(double i = 91.25 ; i <= 800; i += 101.25){ //wall
        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>
                (sf::Vector2f(i,0), sf::FloatRect(0,0,10.0,800.0),wall_texture);
        wall->setColor(sf::Color(255,0,0));
        map["walls"].emplace_back(std::move(wall));
    }
    for(int i = 0 ; i <= 600; i += 150){ //floor
        std::unique_ptr<sf::Sprite> floor = std::make_unique<GameObject>
                (sf::Vector2f(0,i), sf::FloatRect(0,0,800.0,10.0),wall_texture);
        floor->setColor(sf::Color(255,0,0));
        map["floors"].emplace_back(std::move(floor));
    }
}

void Scena::draw(sf::RenderWindow &window){
    for(const auto &el : map){
        for(const auto &v : el.second){
            window.draw(*v);
        }
    }
}

const std::vector<std::unique_ptr<sf::Sprite> > &Scena::getVec(const std::string &key){
    return map[key];
}
