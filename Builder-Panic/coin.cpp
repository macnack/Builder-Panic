#include "coin.h"

int Coin::setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{ // whereAm
    sf::FloatRect bound = this->getGlobalBounds();
    for (unsigned int i = 0; i < platforms.size(); i++)
    {
        if (i + 1 < platforms.size())
        {
            if (platforms[i]->getGlobalBounds().top < bound.top && bound.top < platforms[i + 1]->getGlobalBounds().top)
            {
                return current_stage = i + 1;
            }
        }
    }
    return platforms.size() - 1;
}

void Coin::moveSprite(const sf::Vector2f &dir, const float &dt)
{
    //incrasing speed in the inputed dirction
    velocity += dir * (dt * acceleration);
}

void Coin::updateGravity(const float &dt)
{
    //applying force of gravity
    velocity.y += gravity * dt;
    if (velocity.y > 0.f)
    {
        velocity.y -= 1 / 5.f * gravity * dt; // for coin
    }
}

void Coin::updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    sf::FloatRect playerBounds = this->getGlobalBounds();
    sf::FloatRect playerBoundsNext = this->getGlobalBounds();
    playerBoundsNext.left = getPosition().x + velocity.x * dt;
    playerBoundsNext.top = getPosition().y + velocity.y * dt;
    current_stage = setBounds(platforms);
    sf::FloatRect next_stagePlatformBounds = platforms[current_stage]->getGlobalBounds();
    if (next_stagePlatformBounds.intersects(playerBoundsNext))
    { //bottom
        if (playerBounds.top < next_stagePlatformBounds.top && playerBounds.top + playerBounds.height < next_stagePlatformBounds.top + next_stagePlatformBounds.height && playerBounds.left < next_stagePlatformBounds.left + next_stagePlatformBounds.width && playerBounds.left + playerBounds.width > next_stagePlatformBounds.left)
        {
            velocity.y = -std::abs(velocity.y); // zmiana
            this->setPosition(playerBounds.left, next_stagePlatformBounds.top - playerBounds.height);
        }
    }
    this->updateMovement(dt);
}

void Coin::updateMovement(const float &dt)
{
    this->updateGravity(dt);
    if (velocity.y > 0.f)
    {
        //Max falling velocity check
        //velocity.y -= 1/5.f * gravity * dt; // for coin
        if (velocity.y > maxFallingVelocity)
        {
            velocity.y = maxFallingVelocity;
        }
    }
    if (velocity.x > 0.f)
    { //right
        //deceleration
        velocity.x -= deceleration * dt;
        if (velocity.x < 0.f)
            velocity.x = 0.f;
        //max velocity check
        if (velocity.x > maxVelocity)
            velocity.x = maxVelocity;
    }
    else if (velocity.x < 0.f)
    { //if going left
        //decelaretion
        velocity.x += deceleration * dt;
        if (velocity.x > 0.f)
            velocity.x = 0.f;
        //max velocity check
        if (velocity.x < -maxVelocity)
            velocity.x = -maxVelocity;
    }
    this->move(velocity * dt);
}
