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

bool Coin::is_collected(Hero &gracz1, Hero &gracz2)
{
    sf::FloatRect playerBounds1 = gracz1.getGlobalBounds();
    sf::FloatRect playerBounds2 = gracz2.getGlobalBounds();
    if (this->getGlobalBounds().intersects(playerBounds1))
    {
        gracz1.addScore(value);
        return true;
    }
    if (this->getGlobalBounds().intersects(playerBounds2))
    {
        gracz2.addScore(value);
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
