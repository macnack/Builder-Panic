#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu : public sf::RenderWindow
{
public:
    Menu(sf::RenderWindow *window)
        : window_(window)
    {

    }
private:
    sf::RenderWindow *window_;
};

#endif // MENU_H
