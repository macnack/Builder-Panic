#include "menu.h"


void Menu::start_window(){
    auto start = std::make_unique<sf::Text>("START GAME",font,140);
    start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
    start->setPosition(960,20);
    start->setFillColor(sf::Color(102,51,0));
    start->setOutlineThickness(5);
    start->setOutlineColor(sf::Color::Black);
    map["START"].emplace_back(std::move(start));
    start = std::make_unique<sf::Text>("CREDITS",font,140);
    start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
    start->setPosition(960,170);
    start->setFillColor(sf::Color(102,51,0));
    start->setOutlineThickness(5);
    start->setOutlineColor(sf::Color::Black);
    map["START"].emplace_back(std::move(start));
    start = std::make_unique<sf::Text>("EXIT",font,140);
    start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
    start->setPosition(960,320);
    start->setFillColor(sf::Color(102,51,0));
    start->setOutlineThickness(5);
    start->setOutlineColor(sf::Color::Black);
    map["START"].emplace_back(std::move(start));

}

void Menu::credits_window(){
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
    start->setFillColor(sf::Color::Cyan);
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
    start->setFillColor(sf::Color::Cyan);
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
    start->setFillColor(sf::Color::Cyan);
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
    start->setFillColor(sf::Color::Cyan);
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
    start->setFillColor(sf::Color::Cyan);
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
    start->setFillColor(sf::Color::Cyan);
    map["CREDITS"].emplace_back(std::move(start));
    start = std::make_unique<sf::Text>("BACK",font,60);
    start->setOrigin(start->getLocalBounds().left+start->getLocalBounds().width/2.0,0);
    start->setPosition(960,940);
    start->setFillColor(sf::Color(102,51,0));
    start->setOutlineThickness(5);
    start->setOutlineColor(sf::Color::Black);
    map["CREDITS"].emplace_back(std::move(start));
}

void Menu::pause_window(){
    auto text = std::make_unique<sf::Text>("PAUSE",font,100);
    text->setPosition(850,272);
    map["PAUSE"].emplace_back(std::move(text));
    text = std::make_unique<sf::Text>("HOME",font,60);
    text->setPosition(655,292);
    text->setFillColor(sf::Color(102,51,0));
    text->setOutlineThickness(5);
    text->setOutlineColor(sf::Color::Black);
    map["PAUSE"].emplace_back(std::move(text));
    text = std::make_unique<sf::Text>("EXIT",font,60);
    text->setPosition(1170,292);
    text->setFillColor(sf::Color(102,51,0));
    text->setOutlineThickness(5);
    text->setOutlineColor(sf::Color::Black);
    map["PAUSE"].emplace_back(std::move(text));
    auto player = std::make_unique<sf::Text>("PLAYER ONE",font,60);
    player->setPosition(600,400);
    auto text1 = std::make_unique<sf::Text>("1000",font,60);
    text1->setOrigin(text1->getLocalBounds().left+text1->getLocalBounds().width/2.0,0);
    text1->setPosition((player->getGlobalBounds().left+0.5*player->getGlobalBounds().width),475);
    map["PAUSE"].emplace_back(std::move(player));
    player = std::make_unique<sf::Text>("PLAYER TWO",font,60);
    player->setPosition(1070,400);
    auto text2 = std::make_unique<sf::Text>("1000",font,60);
    text2->setOrigin(text2->getLocalBounds().left+text2->getLocalBounds().width/2.0,0);
    text2->setPosition((player->getGlobalBounds().left+0.5*player->getGlobalBounds().width),475);
    map["PAUSE"].emplace_back(std::move(player));
    map["PAUSE"].emplace_back(std::move(text1));
    map["PAUSE"].emplace_back(std::move(text2));
}

void Menu::pause_update(Hero &en1, Hero &en2)
{
    map["PAUSE"][map["PAUSE"].size()-2]->setString(std::to_string(int(en1.getScore())));
    map["PAUSE"][map["PAUSE"].size()-1]->setString(std::to_string(int(en2.getScore())));
}

void Menu::Draw(){
    if(start)
    {
        for(const auto &m : map[key] )
        {
            window_->draw(*m);
        }
    }
}

void Menu::menu_event(const sf::Event &event,Hero &en1, Hero &en2){
    if (event.type == sf::Event::KeyPressed &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    { // pauza
        pause = !pause;
        start = !start;
        pause_update(en1,en2);
        key = "PAUSE";
    }
    sf::Vector2f mouse_position = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
    for( auto &win : map[key] ){
        if( win->getGlobalBounds().contains(mouse_position)
                && win->getFillColor() == sf::Color(102,51,0)){
            win->setOutlineThickness(5);
            win->setOutlineColor(sf::Color::White);
            if(event.mouseButton.button == sf::Mouse::Left){
                std::string s = win->getString();
                if( s == "EXIT" )
                {
                    window_->close();
                }
                if ( s == "START GAME")
                {
                    start = false;
                    pause = false;
                }
                if( s == "CREDITS")
                {
                    key = "CREDITS";
                }
                if( s == "HOME" || s == "BACK")
                {
                    start = true;
                    key = "START";
                }
            }
        }else{
            win->setOutlineThickness(5);
            win->setOutlineColor(sf::Color::Black);
        }
    }
}
