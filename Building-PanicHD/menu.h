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
    void start_window(){
        auto start = std::make_unique<sf::Text>("START GAME",font,140);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,20);
        map["START"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("CREDITS",font,140);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,170);
        map["START"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("EXIT",font,140);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,320);
        map["START"].emplace_back(std::move(start));

    }
    void credits_window(){
        auto start = std::make_unique<sf::Text>("GAME",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,10);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("MADE BY",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,60);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("Macnack",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,110);
        start->setFillColor(sf::Color(178, 102, 255));
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("ENGINEER CHARACTER",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,170);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("MADE BY",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,220);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("OllieBerzs",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,270);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("COINS",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,330);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("MADE BY",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,380);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("La Red Games",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,430);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("CASTLE TILESET",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,490);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("MADE BY",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,540);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("RottingPixels",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,590);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("Dungeons Walls",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,640);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("MADE BY",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,690);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("Evil_PoisonBR",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,740);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("FONT Fjalla One",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,790);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("Designed by",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,840);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("Sorkin Type ",font,40);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,890);
        map["CREDITS"].emplace_back(std::move(start));
        start = std::make_unique<sf::Text>("BACK",font,60);
        start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
        start->setPosition(960,940);

        //Sorkin Type //
        map["CREDITS"].emplace_back(std::move(start));
    }

    bool start_loop(){
        bool start = false;
        std::string key = "START";
        while ( window_->isOpen())
        {
            sf::Event event;
            if(start){
                break;
            }
            sf::Vector2f mouse_position = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
            while (window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window_->close();
                }
                for( auto &win : map[key] ){
                    if( win->getGlobalBounds().contains(mouse_position) ){
                        win->setOutlineThickness(5);
                        win->setOutlineColor(sf::Color::Black);
                        if(event.mouseButton.button == sf::Mouse::Left){
                            std::string s = win->getString();
                            if( s == "EXIT" )
                            {
                                window_->close();
                            }
                            if ( s == "START GAME")
                            {
                                start = true;
                                key = "START";
                            }
                            if( s == "CREDITS")
                            {
                                key = "CREDITS";
                            }
                            if( s == "BACK" )
                            {
                                key = "START";
                            }
                        }
                    }else{
                        win->setOutlineThickness(0);
                    }
                }
            }

            background->draw();
            for(const auto &m : map[key] )
            {
                window_->draw(*m);
            }
            window_->display();
        }
        return true;
    }
    void pause_window(){
        auto board  = std::make_unique<sf::Sprite>(texture,sf::IntRect(0,0,740,300));
        board->setPosition(600,272);
        board->setColor(sf::Color(139,69,19));
        pause_win_.emplace_back(std::move(board));
        auto text = std::make_unique<sf::Text>("PAUSE",font,100);
        text->setPosition(850,272);
        pause_win_.emplace_back(std::move(text));
    }
    void game_pause(Hero &en1, Hero &en2){
        auto text1 = std::make_unique<sf::Text>("PLAYER ONE\n"+std::to_string(int(en1.getScore())),font,60);
        text1->setPosition(600,400);
        auto text2 = std::make_unique<sf::Text>("PLAYER TWO\n"+std::to_string(int(en2.getScore())),font,60);
        text2->setPosition(1070,400);
        pause_win_.emplace_back(std::move(text1));
        pause_win_.emplace_back(std::move(text2));
        for( const auto &win : pause_win_){
            window_->draw(*win);
        }
        pause_win_.pop_back();
        pause_win_.pop_back();
    }
    void run(){
        while ( window_->isOpen())
        {
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                tekst.setString("Gombao");
                break;
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                tekst.setString("twoja mama");
            }
            sf::Event event;
            while (window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window_->close();
                }
            }
            window_->clear(sf::Color::Black);
            window_->display();
        }}
private:
    sf::RenderWindow *window_;
    std::vector<std::unique_ptr<sf::Drawable>> pause_win_;
    std::vector<std::unique_ptr<sf::Text>> start_win_;
    std::map<std::string,std::vector<std::unique_ptr<sf::Text>>> map;
    std::vector<std::unique_ptr<sf::Text>> credits_win_;
    std::unique_ptr<Scena> background;
    sf::Text tekst;
    sf::Font font;
    sf::Texture texture;
};

#endif // MENU_H
