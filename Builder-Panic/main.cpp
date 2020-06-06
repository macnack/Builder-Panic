#include "objectmanager.h"
#include "cmath"

int main()
{
    float maxHeight = 610.0f;//600
    float maxWidth = 800.0f;//800
    Game game(maxWidth,maxHeight);
    sf::Texture wall_texture;
    if (!wall_texture.loadFromFile("Texture/wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    wall_texture.setRepeated(true);
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
    for(double i = 91.25 ; i <= 800; i += 101.25){ //wall
        std::unique_ptr<sf::Sprite> wall = std::make_unique<Object>
                (sf::Vector2f(i,0), sf::FloatRect(0,0,10.0,800.0),wall_texture);
        wall->setColor(sf::Color(255,0,0));
        map["walls"].emplace_back(std::move(wall));
    }
    for(int i = 0 ; i <= 600; i += 150){ //floor
        std::unique_ptr<sf::Sprite> floor = std::make_unique<Object>
                (sf::Vector2f(0,i), sf::FloatRect(0,0,800.0,10.0),wall_texture);
        floor->setColor(sf::Color(255,0,0));
        map["floors"].emplace_back(std::move(floor));
    }
    double x = 0.f;
    double y = 10.f;
    std::map<int , std::map<int, std::unique_ptr<Object>>> board;
    ObjectManager obj_manager;
    for(int i = 0 ; i < 8; i++){
        for(int k =0; k < 4; k++){
            std::unique_ptr<Object> block_ = std::make_unique<Object>
                    (sf::Vector2f(x,y),sf::FloatRect(0,0,91.25,140),wall_texture);
            obj_manager.add(k,i,std::move(block_));
            y += 150;
        }
        x += 101.25;
        y = 10.0;
    }
    Player gracz(sf::Vector2f(50,100),sf::Vector2f(100,250));



//    int stage;
//    float velocity_y = 0;


    while (game.getWindow().isOpen())
    {
        sf::Time elapsed = game.clock_.restart();
        while (game.window_.pollEvent(game.event))
        {
            if (game.event.type == sf::Event::Closed)
            {
                game.window_.close();
            }
            if (game.event.type == sf::Event::MouseButtonPressed) {
                obj_manager.Paint(game);
            }
            if (game.event.type == sf::Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)  && gracz.current_stage < 4){
                    std::cerr << gracz.current_stage << std::endl;
                    gracz.stage_down = false;
                }
            }
        }
        sf::FloatRect player = gracz.getGlobalBounds();
        sf::FloatRect platform_down;
        sf::FloatRect platform_up;

        gracz.setBounds(map["floors"]);
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(player.top > 10)
                gracz.move(0, -500 * elapsed.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && gracz.stage < 4)
        {
            if(player.top + player.height < map["floors"][gracz.stage+1]->getGlobalBounds().top)
            gracz.move(0, 500 * elapsed.asSeconds());
        }
        if(player.top + player.height > map["floors"][gracz.stage]->getGlobalBounds().top){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(player.left < 0)
                gracz.setPosition(800, player.top);
            gracz.move(-100 * elapsed.asSeconds(),0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(player.left + player.width > 800)
                gracz.setPosition(0, player.top);
            gracz.move(100 * elapsed.asSeconds(),0);
        }
        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gracz.moveSprite(sf::Vector2f(-1.f, 0.f), elapsed.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gracz.moveSprite(sf::Vector2f(1.f, 0.f), elapsed.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
           gracz.moveSprite(sf::Vector2f(0.f, -1.f), elapsed.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            gracz.moveSprite(sf::Vector2f(0.f, 1.f), elapsed.asSeconds());
            //gracz.down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            gracz.jump();
        }

        game.window_.clear(sf::Color::Black);

        for(const auto &wl: map["walls"]){
            game.window_.draw(*wl);
        }
        for(const auto &fl: map["floors"]){
            game.window_.draw(*fl);
        }
        for(const auto &el : obj_manager.board_){
            for(const auto &v : el.second){
                game.window_.draw(*v.second);
            }
        }
        gracz.updateGravity(elapsed.asSeconds());
        gracz.updateMovement(elapsed.asSeconds());
        gracz.updateCollisions(map["floors"], elapsed.asSeconds());
        game.window_.draw(gracz);
        game.window_.display();
    }
    return 0;
}
