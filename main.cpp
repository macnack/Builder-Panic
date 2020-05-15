#include "common_defs.h"
#include "game.h"

using namespace std;
int main()
{
//    Game game;
//    game.run();

    int maxHeight = 610;
    int maxWidth = 795;
    sf::RenderWindow window(sf::VideoMode(maxWidth, maxHeight), "XXX");
    sf::Clock clock;
    r_vec wall; // make walls
    r_vec floor; // make floors
    std::map<double , std::vector<double> > map;
    double x = 95;
    std::vector<double> vec_x;
    vec_x.push_back(0);
    for(int i = 0 ; i < 7; i++){ //wall
        sf::RectangleShape rectangle(sf::Vector2f(5.0, 800.0));
        rectangle.setPosition(x, 0);
        std::cout << x+5 << "\n";
        rectangle.setFillColor(sf::Color(124, 124, 250));
        wall.emplace_back(rectangle);
        vec_x.push_back(x+5);
        x += 100;
    }
    double y = 0;
    for(int i = 0 ; i < 5; i++){ //floor
        sf::RectangleShape rectangle(sf::Vector2f(800.0, 10.0));
        rectangle.setPosition(0, y);
        rectangle.setFillColor(sf::Color(124, 124, 250));
        floor.emplace_back(rectangle);
        map[y+10.0] = vec_x;
        y += 150;
    }
    for(const auto &m : map){
        std::cout << "stage: " << m.first << " ";
        for(const auto &x: m.second){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    r_vec scianka;
    for(auto &m :map){
        for(auto &x : m.second){
            sf::RectangleShape rec(sf::Vector2f(95,140));
            rec.setPosition(x, m.first);
            rec.setFillColor(sf::Color(124,125,124));
            scianka.push_back(rec);
        }
    }

    //sf::RectangleShape
    sf::Vector2f pos(457,480);
    sf::Vector2f size(50, 100);
    Player gracz(size,pos);
    sf::FloatRect player_b = gracz.getGlobalBounds();
    while (window.isOpen())
    {
        sf::Event event;
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                }
            }
        }
        gracz.move(elapsed);
        sf::RectangleShape obiekt;
        obiekt.setSize(sf::Vector2f(80.0, 80.0));
        obiekt.setPosition(205,10);
        obiekt.setFillColor(sf::Color(124, 124, 124));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            //sf::FloatRect player_b = gracz.getGlobalBounds();
            //std::cout << "Current pos: \n y:" << player_b.top+player_b.height << " x: " << player_b.left << "\n";
            for(auto &sc: scianka){
                if(sc.getGlobalBounds().intersects(player_b)){
                    std::cout << "yes yes yes" << endl;
                }
            }

        }
        //obiekt.setPosition(x,y);
        window.clear(sf::Color::Black);
        for(const auto &wl:wall){
            window.draw(wl);
        }
        for(const auto &fl:floor){
            window.draw(fl);
        }
        /*for(const auto &sc:scianka){
            window.draw(sc);
        }*/
        window.draw(obiekt);
        window.draw(gracz);
        window.display();
    }
    return 0;
}
