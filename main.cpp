#include "common_defs.h"
#include "player.h"
using namespace std;
int main()
{
    int maxHeight = 610;
    int maxWidth = 800;
    sf::RenderWindow window(sf::VideoMode(maxWidth, maxHeight), "XXX");
    sf::Clock clock;
    r_vec wall; // make walls
    r_vec floor; // make floors
    std::map<double , std::vector<double> > map;
    double x = 100;
    std::vector<double> vec_x;
    vec_x.push_back(0);
    for(int i = 0 ; i < 7; i++){
        sf::RectangleShape rectangle(sf::Vector2f(5.0, 800.0));
        rectangle.setPosition(x, 0);
        rectangle.setFillColor(sf::Color(124, 124, 250));
        wall.emplace_back(rectangle);
        vec_x.push_back(x+ 5.0);
        x += 100;
    }
    vec_x.push_back(x);
    double y = 0;
    for(int i = 0 ; i < 5; i++){
        sf::RectangleShape rectangle(sf::Vector2f(800.0, 10.0));
        rectangle.setPosition(-5, y);
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
        obiekt.setSize(sf::Vector2f(95.0, 140.0));
        obiekt.setPosition(205,10);
        obiekt.setFillColor(sf::Color(124, 124, 124));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            //sf::FloatRect player_b = gracz.getGlobalBounds();
            //std::cout << "Current pos: \n y:" << player_b.top+player_b.height << " x: " << player_b.left << "\n";
            auto itlow=map.upper_bound (30);
            std::cout << itlow->first;
        }
        //obiekt.setPosition(x,y);
        window.clear(sf::Color::Black);
        for(const auto &wl:wall){
            window.draw(wl);
        }
        for(const auto &fl:floor){
            window.draw(fl);
        }
        window.draw(obiekt);
        window.draw(gracz);
        window.display();
    }
    return 0;
}
