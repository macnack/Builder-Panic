#ifndef MENU_H
#define MENU_H

#include "scena.h"

class Menu : public sf::RenderWindow
{
public:
    const bool &paused();
    const bool &started();
    const bool &restared();
    void start_window();
    void credits_window();
    void pause_window();
    void pause_update(Hero &en1, Hero &en2);
    void Draw();
    void menu_event(const sf::Event &event, Hero &en1, Hero &en2);
    Menu(sf::RenderWindow *window);
private:
    std::string key = "START";
    bool pause = false;
    bool start = true;
    bool restart = false;
    sf::Text tekst;
    sf::Font font;
    sf::Texture texture;
    sf::RenderWindow *window_;
    std::map<std::string,std::vector<std::unique_ptr<sf::Text>>> map;
};

#endif // MENU_H
