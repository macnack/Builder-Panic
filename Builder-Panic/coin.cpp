#include "coin.h"

Coin::Coin(const std::vector<std::unique_ptr<sf::Sprite>> &platforms) : Entity(platforms, rand() % 15, sf::IntRect(0, 0, 16, 16), 7, 4)
{
    bounce = true;
}

bool Coin::is_collected(Hero &gracz)
{
    sf::FloatRect playerBounds = gracz.getGlobalBounds();
    if (this->getGlobalBounds().intersects(playerBounds))
    {
        gracz.addScore(value);
        return true;
    }
    return false;
}

void Coin::loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    this->updateCollisions(platforms, dt);
    this->setTexture(textures_[switcher]);
    this->playAnimation(dt);
}

int Coin::getValue()
{
    return value;
}
