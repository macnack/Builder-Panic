#include "scena.h"
#include "assets.h"

Scena::Scena(sf::RenderWindow *window) : window_(window)
{
    const sf::Texture &floors = cachedTexture("Texture/Dungeons Walls.png", true);
    for (int i = -30; i <= 1080 ; i += 247) //int i = 0; i <= 600; i += 150
    { //floors
        std::unique_ptr<sf::Sprite> floor = std::make_unique<GameObject>(sf::Vector2f(0, static_cast<float>(i)), sf::FloatRect(0, 0, 2000.0, 55.0), floors);
        floor->setColor(sf::Color(139,69,19));
        map["floors"].emplace_back(std::move(floor));
    }
    const sf::Texture &castle = cachedTexture("Texture/castle-tileset.png", true);
    for (double i = 25; i < 1080; i += 247)
    { //walls
        std::unique_ptr<sf::Sprite> wall = std::make_unique<GameObject>(sf::Vector2f(0.f, static_cast<float>(i)), sf::FloatRect(0, 80, 96, 32), castle);
        std::unique_ptr<sf::Sprite> wall2 = std::make_unique<GameObject>(sf::Vector2f(static_cast<float>(96*7.25), static_cast<float>(i)), sf::FloatRect(0, 80, 96, 32), castle);
        std::unique_ptr<sf::Sprite> wall3 = std::make_unique<GameObject>(sf::Vector2f(static_cast<float>(96*7.25*2.0), static_cast<float>(i)), sf::FloatRect(0, 80, 96, 32), castle);
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
    const auto found = map.find(key);
    if (found == map.end())
        throw std::runtime_error("Scena missing layer: " + key);
    return found->second;
}
