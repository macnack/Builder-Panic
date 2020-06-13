#include "hero.h"

Hero::Hero(const sf::Vector2f &pos) : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 9, 8, 3) //docelowy konsturkor
{
    grounded = true;
    bounce = false;
}

void Hero::cooldown(const float &dt)
{
    timer += dt;
    if (!attack_cooldown)
    {
        if (timer > 1)
        {
            timer = 0.f;
            attack_cooldown = true;
        }
    }
    else
    {
        timer = 0.f;
        attack = false;
    }
}

void Hero::getHurt(Hero &hero, const float &dt)
{
    this->untouchable_cooldown(dt);
    if (hero.getGlobalBounds().intersects(this->getGlobalBounds()))
    {
        if (attack == true)
        {
            if (!hero.untouchable)
            { //jesli dostaje bencki velocity.x = 0???
                hero.velocity.y -= 250;
                hero.untouchable = true;
                if (hero.attack == true)
                {
                    hero.velocity.y -= 50;
                    this->velocity.y -= 50;
                }
            }
        }
    }
}

void Hero::untouchable_cooldown(const float &dt)
{
    untouchable_timer += dt;
    if (untouchable)
    {
        if (untouchable_timer > 1.25f)
        {
            untouchable_timer = 0.f;
            untouchable = false;
        }
    }
    else
    {
        untouchable_timer = 0.f;
    }
}

void Hero::attack_move()
{
    attack_cooldown = false;
    attack = true;
}

void Hero::down()
{
    if (stage_down == true && current_stage < 4)
    {
        velocity.y += 200;
        current_stage += 1;
        next_stage = current_stage;
        grounded = false;
        switcher = 2;
    }
}

void Hero::jump()
{
    if (grounded == true && current_stage > 1)
    {
        current_stage -= 1;
        next_stage = current_stage;
        stage_down = false;
    }
    if (grounded)
    {
        velocity.y -= 850;
        switcher = 2;
    }
}

float Hero::addScore(const float &value)
{
    return score += value;
}

float Hero::getScore()
{
    return score;
}

void Hero::moveSprite(const sf::Vector2f &dir, const float &dt)
{
    //incrasing speed in the inputed dirction
    velocity += dir * (dt * acceleration);
}

void Hero::updateMovement(const float &dt)
{
    if (velocity.x != 0)
    {
        switcher = 1;
    }
    if (velocity.y > 0.f)
    {
        //Max falling velocity check
        if (velocity.y > maxFallingVelocity)
        {
            velocity.y = maxFallingVelocity;
        }
    }
    if (velocity.y < 0.f)
    {
        //Max falling velocity check
        if (velocity.y < -maxFallingVelocity)
        {
            velocity.y = -maxFallingVelocity;
        }
    }
    if (velocity.x > 0.f)
    { //right
        //deceleration
        velocity.x -= deceleration * dt;
        if (velocity.x < 0.f)
        {
            velocity.x = 0.f;
        }
        //max velocity check
        if (velocity.x > maxVelocity)
        {
            velocity.x = maxVelocity;
        }
        if (attack_cooldown == false && timer < 0.1)
        {
            velocity.x = attackVelocity;
        }
    }
    else if (velocity.x < 0.f)
    { //if going left
        //decelaretion
        velocity.x += deceleration * dt;
        if (velocity.x > 0.f)
        {
            velocity.x = 0.f;
        }
        //max velocity check
        if (velocity.x < -maxVelocity)
        {
            velocity.x = -maxVelocity;
        }
        if (attack_cooldown == false && timer < 0.1)
        {
            velocity.x = -std::abs(attackVelocity);
        }
    }
    this->setTexture(textures_[switcher]);
    this->playAnimation(dt);
}

void Hero::setColor(Object::Color color)
{
    color_ = color;
}

const Object::Color &Hero::getColor()
{
    return color_;
}
