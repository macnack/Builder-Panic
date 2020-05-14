#include "game.h"
float Game::width = 800;
float Game::height = 610;
std::string Game::name = "STAGE";
sf::Clock Game::clock;
sf::RenderWindow Game::window;
sf::Event Game::event;
void Game::makeWindow(){
    window.create(sf::VideoMode(width, height), name);
}
Game::Game()
{
    makeWindow();
}
Game::~Game(){

}
void Game::update(){
    //game loop
}
void Game::render(){
    //game draw
}
const sf::RenderWindow &Game::Window() const
{
    return window;
}
void Game::run(){
    gracz.paint();
    while(Window().isOpen()){
        update();
        render();
        window.clear(sf::Color::Black);
        window.display();
    }
//        sf::Time elapsed = clock.restart();
//        gracz.move(elapsed);
//        window_.clear(sf::Color::Black);
//        window_.draw(gracz);
//        window_.display();
}
