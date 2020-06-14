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
//    for (double i = 217; i <= 1920; i += 217 + 25 )
//    { //wall
//        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>(sf::Vector2f(i, 0), sf::FloatRect(0, 0, 25, 1080), texture);
//        wall->setColor(sf::Color(255, 0, 0));
//        map["awalls"].emplace_back(std::move(wall));
//    }
//    double x = 0.;
//    double y = 25.0;
//    for (int i = 0; i < 8; i++)
//    {
//        for (int k = 0; k < 4; k++)
//        {
//            std::unique_ptr<sf::Sprite> block = std::make_unique<GameObject>(sf::Vector2f(x, y), texture);
//            block->setOrigin(block->getLocalBounds().left + block->getLocalBounds().width, block->getLocalBounds().top + block->getLocalBounds().height);
//            block->setRotation(180);
//            map["p_walls"].emplace_back(std::move(block));
//            y += 247;
//        }
//        x += 217 + 25;
//        y = 25.0 ;
//    }
    if (!texture.loadFromFile("Texture/castle-tileset.png"))
    {
        throw("Could not load texture 'Castle Tileset'");
    }
    texture.setRepeated(true);
    for (double i = 25; i <= 1080; i += 247) // 8 double i = 91.25; i <= 800; i += 101.25
    { //wall
        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>(sf::Vector2f(0, i), sf::FloatRect(9, 80, 96, 32), texture);
        std::unique_ptr<sf::Sprite> wall2 = std::make_unique<GameObject>(sf::Vector2f(96*8, i), sf::FloatRect(9, 80, 96, 32), texture);
        std::unique_ptr<sf::Sprite> wall3 = std::make_unique<GameObject>(sf::Vector2f(96*8*2.0, i), sf::FloatRect(9, 80, 96, 32), texture);
        wall->setScale(8,6);
        wall2->setScale(8,6);
        wall3->setScale(8,6);
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
