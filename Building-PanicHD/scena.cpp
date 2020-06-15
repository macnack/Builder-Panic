#include "scena.h"

Scena::Scena(sf::RenderWindow *window) : window_(window)
{
    if (!texture.loadFromFile("Texture/Dungeons Walls.png"))
    {
        throw("Could not load texture 'Dungeons Walls'");
    }
    texture.setRepeated(true);
    for (int i = -30; i <= 1080 ; i += 247) //int i = 0; i <= 600; i += 150
    { //floor
        std::unique_ptr<sf::Sprite> floor = std::make_unique<GameObject>(sf::Vector2f(0, i), sf::FloatRect(0, 0, 2000.0, 55.0), texture);
        floor->setColor(sf::Color(139,69,19));
        map["floors"].emplace_back(std::move(floor));
    }
    if (!texture.loadFromFile("Texture/castle-tileset.png"))
    {
        throw("Could not load texture 'Castle Tileset'");
    }
    texture.setRepeated(true);
    for (double i = 25; i < 1080; i += 247)
    { //wall
        std::cerr << i << std::endl;
        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>(sf::Vector2f(0, i), sf::FloatRect(0, 80, 96, 32), texture);
        std::unique_ptr<sf::Sprite> wall2 = std::make_unique<GameObject>(sf::Vector2f(96*7.25, i), sf::FloatRect(0, 80, 96, 32), texture);
        std::unique_ptr<sf::Sprite> wall3 = std::make_unique<GameObject>(sf::Vector2f(96*7.25*2.0, i), sf::FloatRect(0, 80, 96, 32), texture);
        wall->setScale(7.25,6);
        wall2->setScale(7.25,6);
        wall3->setScale(7.25,6);
        map["walls"].emplace_back(std::move(wall));
        map["walls"].emplace_back(std::move(wall2));
        map["walls"].emplace_back(std::move(wall3));
    }
}

void Scena::draw()
{
    for (const auto &el : map)
    {
        for (const auto &v : el.second)
        {
            window_->draw(*v);
        }
    }
}

const std::vector<std::unique_ptr<sf::Sprite>> &Scena::getVec(const std::string &key)
{
    return map[key];
}
