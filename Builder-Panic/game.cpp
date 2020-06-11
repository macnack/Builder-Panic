#include "game.h"

void Game::draw()
{
    //draw here
    //    for(const auto &wl: map["walls"]){
    //        window_.draw(*wl);
    //    }
    //    for(const auto &fl: map["floors"]){
    //        window_.draw(*fl);
    //    }
    scena.draw();
    for (const auto &el : obj_manager->getBoard())//obj_mangaer->draw(window_)
    {
        for (const auto &v : el.second)
        {
            window_.draw(*v.second);
        }
    }
    for(const auto &c: coins){
        window_.draw(*c);
    }
    window_.draw(*gracz);//gracz->draw()
    window_.draw(*enemy);//-||-
}
void Game::run()
{
    //game loop
    while (window_.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Time elapsed = clock_.restart();
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                obj_manager->Paint(window_, event);
            }
            if (event.type == sf::Event::KeyPressed)
            {
                gracz->change_platform();
                enemy->change_platform();
                obj_manager->Paint(*gracz);
                obj_manager->Paint(*enemy);
            }
        }
        gracz->playAnimation(elapsed.asSeconds());
        enemy->playAnimation(elapsed.asSeconds());
        for(auto it = coins.begin(); it < coins.end() ; it++ ){
            (*it)->playAnimation(elapsed.asSeconds());
            if((*it)->is_collected(*gracz) || (*it)->is_collected(*enemy)){
                std::cerr << "Collected coin +50" << std::endl;
                coins.erase(it);
            }
        }

        enemy->loop(scena.getVec("floors"), elapsed.asSeconds());
        gracz->loop(scena.getVec("floors"), elapsed.asSeconds());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        { // usun kolory
            for (auto &k : obj_manager->getBoard())
            {
                for (auto &obj : k.second)
                {
                    Object *as_obj = dynamic_cast<Object *>(obj.second.get());
                    as_obj->Paint(Object::Color::Default);
                }
            }
        }
        if (obj_manager->full_board())
        {
            std::cerr << "koniec" << std::endl;
        }
        window_.clear(sf::Color::Black);
        this->draw();

        window_.display();
    }
}

Game::Game(const float &w, const float &h) : window_(sf::VideoMode(w, h), "Bulding Panic"), scena(&window_)
{
    sf::Clock clock;
    clock_ = clock;
    sf::Texture wall_texture;
    if (!wall_texture.loadFromFile("Texture/Dungeons Walls.png"))
    {
        throw("Could not load texture 'Dungeons Walls'");
    }
    wall_texture.setRepeated(true);
    sf::Texture coin_texture;
    if (!coin_texture.loadFromFile("Texture/MonedaD.png"))
    {
        throw("Could not load texture 'Coin'");
    }
    //scena = std::make_unique<Scena>(&window_);
    obj_manager = std::make_unique<ObjectManager>(wall_texture);
//    sf::Texture hero_texture;
//    if (!hero_texture.loadFromFile("Texture/engineer character/engineer.png"))
//    {
//        throw("Could not load texture 'Engineer Idle'");
//    }
    sf::Texture indle_texture;
    if (!indle_texture.loadFromFile("Texture/engineer character/engineer-idle.png"))
    {
        throw("Could not load texture 'Engineer Idle'");
    }
    //Animation idles(hero_texture, sf::IntRect(0,0,16,28), 7, 4);
    //          run(..., sf::IntRect(0, 0, 16, 28), 12, 8)
    gracz = std::make_unique<Player>(sf::Vector2f(100,250), indle_texture, sf::IntRect(0, 0, 16, 28), 14, 9);
    enemy = std::make_unique<Enemy>(sf::Vector2f(100,250), indle_texture, sf::IntRect(0, 0, 16, 28), 14, 9);
    for(int x = 150; x < 800 ; x+=150){
        std::unique_ptr<Coin> coin = std::make_unique<Coin>(sf::Vector2f(x, 350), coin_texture, sf::IntRect(0, 0, 16, 16), 7, 4);
        coins.push_back(std::move(coin));
    }
    /* Przeniesione konstrukcja  objectmanager */
    {
        //    double x = 0.f;
        //    double y = 10.f;
        //    for(int i = 0 ; i < 8; i++){
        //        for(int k =0; k < 4; k++){
        //            std::unique_ptr<Object> block_ = std::make_unique<Object>
        //                    (sf::Vector2f(x,y),sf::FloatRect(0,0,91,140),wall_texture);
        //            //Sceny testowe:
        //            //wspolrzedne [k][i]
        //            //scena 1
        //            //1. lewy  [1][2]
        //            //2. prawy [2][2]
        //            //3. lewy  [0][5] : obiekt [2][3] nie powinien zmieniac koloru
        //            //            if( (k == 1 && i == 3) || (k == 2 && i == 4) || ( k == 0 && i == 2)){
        //            //                block_->Paint(Object::Color::Enemy);
        //            //            }
        //            //            if( (k == 1 && i == 4) || (k == 2 && i == 3) || ( k == 3 && i == 2)){
        //            //                block_->Paint(Object::Color::Player);
        //            //            }
        //            //scena 2:
        //            //1. lewy  [2][2]
        //            //2. prawy [1][5]
        //            //3. prawy [1][6] : obiekt [1][2] nie powinien zmieniac koloru
        //            //            if( (k == 0 && i == 2) || ( k == 1 && (i == 0 || i == 4 ))){
        //            //                block_->Paint(Object::Color::Player);
        //            //            }
        //            //            if( k==1 && ( i == 1 || i == 2 || i == 3)){
        //            //                block_->Paint(Object::Color::Enemy);
        //            //            }
        //            obj_manager.add(k,i,std::move(block_));
        //            y += 150;
        //        }
        //        x += 101.25;
        //        y = 10.0;
        //    }
    }
}
