#include "player.h"

void Player::move_(const sf::Time &elapsed)
{

    sf::FloatRect player = sf::RectangleShape::getGlobalBounds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(player.top > 10)
        sf::RectangleShape::move(0, -500 * elapsed.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(player.top + player.height < 600)
        sf::RectangleShape::move(0, 500 * elapsed.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(player.left < 0)
            sf::RectangleShape::setPosition(800, player.top);
        sf::RectangleShape::move(-500 * elapsed.asSeconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(player.left + player.width > 800)
            sf::RectangleShape::setPosition(0, player.top);
        sf::RectangleShape::move(500 * elapsed.asSeconds(), 0);
    }
}
void Player::paint(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        sf::FloatRect player = sf::RectangleShape::getGlobalBounds();
        sf::RectangleShape (sf::Vector2f(800.0, 10.0));
        sf::RectangleShape::setPosition(player.top, player.top);
        sf::RectangleShape::setFillColor(sf::Color(124, 124, 124));
    }
}
