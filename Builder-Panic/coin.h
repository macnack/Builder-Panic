#ifndef COIN_H
#define COIN_H
#include "animation.h"
#include "entity.h"
class Coin : public Animation
{
public:
    void random_coin(const int &x)
    {
        if (x < 9)
        {
            value = 25;
            if (!texture.loadFromFile("Texture/MonedaR.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }
        else if (x >= 9 && x < 13)
        {
            value = 50;
            if (!texture.loadFromFile("Texture/MonedaP.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }
        else
        {
            value = 100;
            if (!texture.loadFromFile("Texture/MonedaD.png"))
            {
                throw("Could not load texture 'Coin'");
            }
        }
    }
    Coin(const sf::Vector2f &pos) : Animation(sf::IntRect(0, 0, 16, 16), 7, 4)
    {
        random_coin(rand() % 15);
        current_stage = rand() % 4;
        this->setPosition(pos);
        this->setScale(3, 3);
        this->setTexture(texture);
        bound = this->getLocalBounds();
    }
    Coin() : Animation(sf::IntRect(0, 0, 16, 16), 7, 4)
    {
        random_coin(rand() % 15);
        current_stage = rand() % 4;
        this->setPosition(sf::Vector2f(rand() % 700, rand() % 500));
        this->setScale(3, 3);
        this->setTexture(texture);
        bound = this->getLocalBounds();
    }
    bool is_collected(Entity &postac)
    {
        if (this->getGlobalBounds().intersects(postac.getGlobalBounds()))
        {
            return true;
        }
        return false;
    }
    ~Coin()
    {
        std::cerr << "Collected coin +" << value << std::endl;
    }
    //zapozyczone z entity
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    void moveSprite(const sf::Vector2f &dir, const float &dt);
    void updateMovement(const float &dt);
    void updateGravity(const float &dt);
    void updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);

private:
    int value;
    sf::FloatRect bound;
    sf::Texture texture;
    //zapozyczone z entity
    int current_stage = 4; //define?
    int next_stage = current_stage;
    sf::Vector2f velocity;
    float gravity = 2000;
    float acceleration = 4800.f;
    float deceleration = 1500;
    float maxFallingVelocity = 1500.f;
    float maxVelocity = 500.f;
};

#endif // COIN_H
