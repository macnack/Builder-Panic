#ifndef GAME_H
#define GAME_H
#include "scena.h"
class Game : public sf::RenderWindow
{
public:
    void run();
    void draw();
    void update();
    Game(const float &w, const float &h);
    virtual ~Game() = default;;
    const sf::RenderWindow &getWindow();
    const sf::Clock &getClock();
    const sf::Event &getEvent();
    sf::RenderWindow window_; //to private
    sf::Event event; //to private
    sf::Clock clock_; // to private
private:
    ObjectManager obj_manager;
    std::unique_ptr<Scena> scena;
    std::unique_ptr<Player> gracz;
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
    std::string title;
    float width_;
    float height_;
};

#endif // GAME_H
