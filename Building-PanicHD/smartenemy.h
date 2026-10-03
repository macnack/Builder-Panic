#ifndef SMARTENEMY_H
#define SMARTENEMY_H

#include "hero.h"

class ObjectManager;

// CPU painter. Patrols and paints, chases the player up close, and
// yields to arrow keys / N / M until the round is reset.
class SmartEnemy : public Hero
{
public:
    void loop(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, const float &dt);
    void sense(Hero &player, const ObjectManager &walls);
    void resetRound();
    bool painting();
    virtual ~SmartEnemy() = default;
    SmartEnemy(const sf::Vector2f &pos);

private:
    void change_platform();
    void think(const std::vector<std::unique_ptr<sf::Sprite>> &platforms, float dt);
    bool read_human_keys() const;

    bool human_controlled_ = false;
    bool want_paint_ = false;
    bool want_jump_ = false;
    bool want_down_ = false;
    bool want_attack_ = false;
    int patrol_dir_ = -1;
    float steer_x_ = 0.f;
    float decision_timer_ = 0.f;
    float chase_timer_ = 0.f;
    float stuck_timer_ = 0.f;
    float last_x_ = 0.f;
    Hero *player_ = nullptr;
    const ObjectManager *walls_ = nullptr;
};

#endif // SMARTENEMY_H
