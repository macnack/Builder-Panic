#include "entity.h"

int Entity::setBounds(const std::vector<std::unique_ptr<sf::Sprite>> &platforms)
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




void Entity::updateGravity(const float &dt)
{
    //applying force of gravity
    velocity.y += gravity * dt;
}

void Entity::updateMovement(const float &dt)
{
    this->updateGravity(dt);
    if(velocity.x != 0){
        switcher = 1;
    }
    if (velocity.y > 0.f)
    {
        //Max falling velocity check
        velocity.y -= 1/5.f * gravity * dt; // for coin
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
    this->setTexture(textures_[switcher]);
    this->playAnimation(dt);
    this->move(velocity * dt);
}

void Entity::updateCollisions(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt)
{
    grounded = false;
    sf::FloatRect playerBounds = this->getGlobalBounds();
    sf::FloatRect playerBoundsNext = this->getGlobalBounds();
    playerBoundsNext.left = getPosition().x + velocity.x * dt;
    playerBoundsNext.top = getPosition().y + velocity.y * dt;
    current_stage = setBounds(platforms);
    sf::FloatRect next_stagePlatformBounds = platforms[next_stage]->getGlobalBounds();
    if(bounce){
        next_stagePlatformBounds = platforms[current_stage]->getGlobalBounds();
    }
    if (next_stagePlatformBounds.intersects(playerBoundsNext))
    { //bottom
        if (playerBounds.top < next_stagePlatformBounds.top && playerBounds.top + playerBounds.height < next_stagePlatformBounds.top + next_stagePlatformBounds.height && playerBounds.left < next_stagePlatformBounds.left + next_stagePlatformBounds.width && playerBounds.left + playerBounds.width > next_stagePlatformBounds.left)
        {
            if(!bounce){
                velocity.y = 0;
            }else{
                velocity.y = -std::abs(velocity.y);
            }
            switcher = 0;
            grounded = true;
            stage_down = true;
            this->setPosition(playerBounds.left, next_stagePlatformBounds.top - playerBounds.height);
        }
    }
    if (playerBounds.top + playerBounds.height > 800)
    { //zapobiega spadaniu
        this->setPosition(playerBounds.left, next_stagePlatformBounds.top - playerBounds.height);
    }
    if ((playerBounds.left + playerBounds.width) < 5)
    { //przejsce w lewo
        this->setPosition(800 - playerBounds.left - playerBounds.width, next_stagePlatformBounds.top - playerBounds.height);
    }
    if ((playerBounds.left) > 795)
    { //przejscie w prawo
        this->setPosition(-(50) / 2.0, next_stagePlatformBounds.top - playerBounds.height);
    }
    this->updateMovement(dt);
}
