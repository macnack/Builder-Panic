#ifndef MENU_H
#define MENU_H

#include "scena.h"

class Menu : public sf::RenderWindow
{
public:
    const bool &paused();
    const bool &started();
    const bool &restarted();
    bool game_mode();
    bool lobbie_mode();
    void pause_update(Hero &en1, Hero &en2);
    void end_update(Hero &en1, Hero &en2);
    void Draw();
    void reset();
    void menu_event(const sf::Event &event, Hero &en1, Hero &en2);
    Menu(sf::RenderWindow *window);
private:
    bool pause = false; //time pause
    bool start = true; //view 'GUI'
    bool restart = false;
    void start_window();
    void credits_window();
    void pause_window();
    void end_window();
    sf::Text tekst;
    sf::Font font;
    sf::Texture texture;
    sf::RenderWindow *window_;
    std::string key = "START";
    std::map<std::string,std::vector<std::unique_ptr<sf::Text>>> map;
};

#endif // MENU_H
