#include "coin.h"

bool Coin::is_collected(const Player &gracz)
{
    sf::FloatRect playerBounds = gracz.getGlobalBounds();
    if (this->getGlobalBounds().intersects(playerBounds))
    {
        return true;
    }
    return false;
}


