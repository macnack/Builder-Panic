#ifndef PLAYER_H
#define PLAYER_H
#include "common_defs.h"

class Player : public sf::RectangleShape
{
public:
    Player(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size)
    {
        sf::RectangleShape::setPosition(pos);
    }
    void setBounds(r_vec);
    void move(const sf::Time &elapsed)
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
    void paint(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            sf::FloatRect player = sf::RectangleShape::getGlobalBounds();
            sf::RectangleShape (sf::Vector2f(800.0, 10.0));
            sf::RectangleShape::setPosition(player.top, player.top);
            sf::RectangleShape::setFillColor(sf::Color(124, 124, 124));
        }
    }
private:
    double feet = 600;
};

#endif // PLAYER_H
