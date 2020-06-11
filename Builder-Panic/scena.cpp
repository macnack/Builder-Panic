#include "scena.h"

Scena::Scena(sf::RenderWindow *window) : window_(window)
{
    if (!texture.loadFromFile("Texture/Dungeons Walls.png"))
    {
        throw("Could not load texture 'Dungeons Walls'");
    }
    texture.setRepeated(true);
    for (double i = 91.25; i <= 800; i += 101.25)
    { //wall
        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>(sf::Vector2f(i, 0), sf::FloatRect(0, 0, 10.0, 600.0), texture);
        wall->setColor(sf::Color(255, 0, 0));
        map["walls"].emplace_back(std::move(wall));
    }
    for (int i = 0; i <= 600; i += 150)
    { //floor
        std::unique_ptr<sf::Sprite> floor = std::make_unique<GameObject>(sf::Vector2f(0, i), sf::FloatRect(0, 0, 850.0, 10.0), texture);
        floor->setColor(sf::Color(255, 0, 0));
        map["floors"].emplace_back(std::move(floor));
    }
    double x = 0.f;
    double y = 10.f;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            std::unique_ptr<sf::Sprite> block = std::make_unique<GameObject>(sf::Vector2f(x, y), sf::FloatRect(0, 0, 91, 140), texture);
            block->setOrigin(block->getLocalBounds().left + block->getLocalBounds().width, block->getLocalBounds().top + block->getLocalBounds().height);
            block->setRotation(180);
            map["p_walls"].emplace_back(std::move(block));
            y += 150;
        }
        x += 101.25;
        y = 10.0;
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
