#include "hero.h"

Hero::Hero(const sf::Vector2f &pos, const Object::Color &color)
    : Entity(pos, sf::IntRect(0, 0, 16, 28), 14, 8, 8, 3), color_(color)
{
    if(color_ == Object::Color::Enemy){
        this->setColor(sf::Color(178, 102, 255));
    }
    RGB = this->getColor();
    grounded = true;
    bounce = false;
}

void Hero::cooldown(const float &dt)
{
    timer += dt;
    if (!attack_cooldown)
    {
        if (timer > timer_elapsed)
        {
            timer = timer_reset;
            attack_cooldown = true;
        }
    }
    else
    {
        timer = timer_reset;
        attack = false;
    }
}

void Hero::wall_painting(const float &dt){
    if( this->painting() ){
        painting_timer -= dt;
        paint = false;
    }else {
        painting_timer = painting_start;
        paint = false;
    }
    if(painting_timer < painting_stop){
        painting_timer = painting_start;
        paint = true;
    }
}

void Hero::change_platform_cooldown(const float &dt){
    change_platform_timer += dt;
    if (!can_change)
    {
        if (change_platform_timer > change_platform_elapsed)
        {
            change_platform_timer = change_platform_reset;
            can_change = true;
        }
    }
    else
    {
        change_platform_timer = change_platform_reset;
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
            {
                hero.velocity.y -= 450;
                hero.untouchable = true;
                hero.is_stunned = true;
                if (hero.attack == true)
                {
                    hero.velocity.y -= 50;
                    this->velocity.y -= 50;
                }
            }
        }
    }
    if(is_stunned){
        switcher = 3;
    }
}

sf::Vector2f Hero::view()
{
    return sf::Vector2f(  this->getGlobalBounds().left, this->getGlobalBounds().top);
}

void Hero::untouchable_cooldown(const float &dt)
{
    untouchable_timer += dt;
    if (untouchable)
    {
        if(untouchable_timer > 0.1){
            this->setColor(sf::Color::Red);
        }
        if(untouchable_timer > snapshot_color){
            this->setColor(sf::Color(RGB.r, RGB.g, RGB.b));
        }
        if(untouchable_timer > snapshot_color*2){
            this->setColor(sf::Color::Red);
        }
        if(untouchable_timer > snapshot_color*3){
            this->setColor(sf::Color(RGB.r, RGB.g, RGB.b));
        }
        if(untouchable_timer > snapshot_color*4){
            this->setColor(sf::Color::Red);
        }
        if(untouchable_timer > snapshot_color*5){
            this->setColor(sf::Color(RGB.r, RGB.g, RGB.b));
        }
        if(untouchable_timer > stunned_elapsed){
            is_stunned = false;
        }
        if (untouchable_timer > untouchable_elapsed )
        {
            untouchable_timer = untouchable_reset;
            untouchable = false;
        }
    }
    else
    {
        untouchable_timer = untouchable_reset;
    }
}

void Hero::attack_move()
{
    attack_cooldown = false;
    attack = true;
}

void Hero::painting_move()
{
    paint_cooldown = false;
    paint = true;
}

void Hero::down()
{
    if (can_change && stage_down && current_stage < 4)
    {
        velocity.y += 450;
        current_stage += 1;
        next_stage = current_stage;
        grounded = false;
        can_change = false;
        switcher = 2;
    }
}

void Hero::jump()
{
    if ( can_change && grounded )
    {
        velocity.y -= 1000;
        switcher = 2;
        if( current_stage > 1)
        {
            current_stage -= 1;
            next_stage = current_stage;
            stage_down = false;
            can_change = false;
        }
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
{ //incrasing speed in the inputed dirction
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
        if (attack_cooldown == false && timer < 0.1)// attack dash
        {
            velocity.y = std::abs(attackVelocity);
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
        this->setFaceRight(true);
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
        if (attack_cooldown == false && timer < 0.1)// attack dash
        {
            velocity.x = attackVelocity;
            this->setColor(sf::Color(128, 128, 128));
        }else{
            this->setColor(sf::Color(RGB.r, RGB.g, RGB.b));
            //attack = false;
        }
    }
    else if (velocity.x < 0.f)
    { //if going left
        //decelaretion
        this->setFaceRight(false);
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
        if (attack_cooldown == false && timer < 0.1) // attack dash
        {
            velocity.x = -std::abs(attackVelocity);
            this->setColor(sf::Color(128, 128, 128));
        }else{
            this->setColor(sf::Color(RGB.r, RGB.g, RGB.b));
        }
    }
    this->setTexture(textures_[switcher]);
    this->playAnimation(dt);
}

void Hero::setColor_flag(Object::Color color)
{
    color_ = color;
}

bool Hero::stunned()
{
    return is_stunned;
}

bool Hero::can_paint()
{
    return paint;
}

const Object::Color &Hero::getColor_Object()
{
    return color_;
}
