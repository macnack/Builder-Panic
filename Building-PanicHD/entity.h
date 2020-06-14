#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"
class Entity : public Animation
{
public:
    int setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms);
    void updateGravity(const float &dt);
    void updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    Entity(const sf::Vector2f &pos, const sf::IntRect &frame, const float &framerate,
           const int &len_idle, const int &len_move, const int &len_jump)
        : Animation(frame, framerate)
    {
        this->setScale(6, 6);
        this->setPosition(pos);
        sf::Texture indle_texture;
        if (!indle_texture.loadFromFile("Texture/engineer character/engineer-idle.png"))
        {
            throw("Could not load texture 'Engineer Idle'");
        }
        frames_.push_back(addAnimation(frame, len_idle));
        textures_.push_back(indle_texture);
        sf::Texture run_texture;
        if (!run_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
        {
            throw("Could not load texture 'Engineer Run'");
        }
        frames_.push_back(addAnimation(frame, len_move));
        textures_.push_back(run_texture);
        sf::Texture jump_texture;
        if (!jump_texture.loadFromFile("Texture/engineer character/engineer-jump.png"))
        {
            throw("Could not load texture 'Engineer Jump'");
        }
        frames_.push_back(addAnimation(frame, len_jump));
        textures_.push_back(jump_texture);
        this->setTexture(textures_[0]);
    }
    //not in usse
    Entity(const sf::Vector2f &pos, const sf::IntRect &frame,
           const float &framerate) : Animation(frame, framerate)
    {
        this->setScale(3.5, 3.5);
        this->setPosition(pos);
        sf::Texture indle_texture;
        if (!indle_texture.loadFromFile("Texture/engineer character/engineer-idle.png"))
        {
            throw("Could not load texture 'Engineer Idle'");
        }
        textures_.push_back(indle_texture);
        frames_.push_back(addAnimation(frame, 9));
        sf::Texture run_texture;
        if (!run_texture.loadFromFile("Texture/engineer character/engineer-run.png"))
        {
            throw("Could not load texture 'Engineer Run'");
        }
        frames_.push_back(addAnimation(frame, 8));
        textures_.push_back(run_texture);
        sf::Texture jump_texture;
        if (!jump_texture.loadFromFile("Texture/engineer character/engineer-jump.png"))
        {
            throw("Could not load texture 'Engineer Jump'");
        }
        frames_.push_back(addAnimation(frame, 3));
        textures_.push_back(jump_texture);
        this->setTexture(textures_[0]);
    }
    Entity(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const int &x, const sf::IntRect &frame,
           const float &framerate, const float &lenght) : Animation(frame, framerate, lenght)
    {
        this->setScale(4, 4);
        sf::Texture texture;
        if (x < 9)
        {
            if (!texture.loadFromFile("Texture/MonedaR.png"))
            {
                throw("Could not load texture 'CoinR'");
            }
            value = 25;
        }
        else if (x >= 9 && x <= 13)
        {
            if (!texture.loadFromFile("Texture/MonedaP.png"))
            {
                throw("Could not load texture 'CoinP'");
            }
            value = 50;
        }
        else
        {
            if (!texture.loadFromFile("Texture/MonedaD.png"))
            {
                throw("Could not load texture 'CoinD'");
            }
            value = 100;
        }
        textures_.push_back(texture);
        this->setTexture(texture);
        this->setPosition(sf::Vector2f(rand() % 1820, rand() % 1030));
        current_stage = setBounds(platforms);
        next_stage = current_stage;
        for (auto &pl : platforms)
        {
            while (pl->getGlobalBounds().intersects(this->getGlobalBounds()))
            {
                this->setPosition(sf::Vector2f(rand() % 1820, rand() % 1030));
            }
        }
    }
    virtual ~Entity() = default;
    sf::Vector2f view()
    {
        return sf::Vector2f(  this->getGlobalBounds().left, this->getGlobalBounds().top);
    }
protected:
    int value;
    bool bounce = false;
    bool stage_down = false;
    bool grounded = false;
    int current_stage = 4; //define?
    int next_stage = current_stage;
    sf::Vector2f velocity;
    float gravity = 2000;
};

#endif // ENTITY_H
