#ifndef MENU_H
#define MENU_H

#include "scena.h"

class Game;
class Menu : public sf::RenderWindow
{
public:
    Menu(sf::RenderWindow *window)
        : window_(window)
    {
        font.loadFromFile("Font/FjallaOne-Regular.ttf");
        if (!texture.loadFromFile("Texture/Dungeons Walls.png"))
        {
            throw("Could not load texture 'Dungeons Walls'");
        }
        texture.setRepeated(true);
        background = std::make_unique<Scena>(window_);
        pause_window();
        start_window();
        credits_window();
    }
    void start_window();
    void credits_window();
    void pause_window();
    void pause_update(Hero &en1, Hero &en2);
    void Draw();
    void menu_event(const sf::Event &event, Hero &en1, Hero &en2);
//    bool start_loop(){
//        bool start = false;
//        int sto = 100;
//        int dwa = 2;
//        //game_pause(sto,dwa);
//        while ( window_->isOpen())
//        {
//            if(start){
//                break;
//            }
//            sf::Event event;
//            sto += 1000;
//            dwa += 557;
//            while (window_->pollEvent(event))
//            {
//                if (event.type == sf::Event::Closed)
//                {
//                    window_->close();
//                }
//                if (event.type == sf::Event::KeyPressed &&
//                        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//                { // pauza
//                    pause = !pause;
//                }
//                sf::Vector2f mouse_position = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
//                for( auto &win : map[key] ){
//                    if( win->getGlobalBounds().contains(mouse_position)
//                            && win->getFillColor() == sf::Color(102,51,0)){
//                        win->setOutlineThickness(5);
//                        win->setOutlineColor(sf::Color::White);
//                        if(event.mouseButton.button == sf::Mouse::Left){
//                            std::string s = win->getString();
//                            if( s == "EXIT" )
//                            {
//                                window_->close();
//                            }
//                            if ( s == "START GAME")
//                            {
//                                //start = true;
//                                pause = !pause;
//                                key = "PAUSE";
//                            }
//                            if( s == "CREDITS")
//                            {
//                                key = "CREDITS";
//                            }
//                            if( s == "HOME" || s == "BACK")
//                            {
//                                key = "START";
//                            }
//                        }
//                    }else{
//                        win->setOutlineThickness(5);
//                        win->setOutlineColor(sf::Color::Black);
//                    }
//                }

//            }

//            background->draw();
//            for(const auto &m : map[key] )
//            {
//                window_->draw(*m);
//            }
//            if(pause){
//                map["PAUSE"].pop_back();
//                map["PAUSE"].pop_back();
//                game_pause(sto,dwa);
//                pause = false;
//            }
//            window_->display();
//        }
//        return true;
//    }

    std::map<std::string,std::vector<std::unique_ptr<sf::Text>>> map;
    const bool &paused(){
        return pause;
    }
private:
    std::string key = "START";
    bool pause = false;
    bool start = true;
    sf::RenderWindow *window_;
    std::vector<std::unique_ptr<sf::Drawable>> pause_win_;
    std::unique_ptr<Scena> background;
    sf::Text tekst;
    sf::Font font;
    sf::Texture texture;
};

#endif // MENU_H
