#include "game.h"
#include "assets.h"

#include <iostream>

void Game::draw()
{
    scena.draw();
    obj_manager->draw();
    for (const auto &c : coins)
    {
        window_.draw(*c);
    }
    window_.draw(*gracz);
    window_.draw(*enemy);
    menu.Draw();
}

void Game::ensure_lobby_coins()
{
    const auto &floors = scena.getVec("floors");
    while (coins.size() < 10)
        coins.push_back(std::make_unique<Coin>(floors));
}

void Game::update(const float &dt)
{
    if (menu.paused())
        return;

    const auto &floors = scena.getVec("floors");
    obj_manager->Paint(*gracz);
    obj_manager->Paint(*enemy);
    gracz->getHurt(*enemy, dt);
    enemy->getHurt(*gracz, dt);
    gracz->loop(floors, dt);
    enemy->sense(*gracz, *obj_manager);
    enemy->loop(floors, dt);

    if (menu.game_mode())
    {
        timer += dt;
        if (timer > 5.f)
        {
            if (coins.size() < 4)
                coins.push_back(std::make_unique<Coin>(floors));
            timer = 0.f;
        }
    }

    int spawned = 0;
    for (auto it = coins.begin(); it != coins.end();)
    {
        (*it)->loop(floors, dt);
        if ((*it)->is_collected(*gracz, *enemy))
        {
            it = coins.erase(it);
            if (coin_sound_)
                coin_effect.play();
            if (menu.lobbie_mode())
                ++spawned;
        }
        else
        {
            ++it;
        }
    }
    while (spawned-- > 0)
        coins.push_back(std::make_unique<Coin>(floors));
}

void Game::restart()
{
    if (menu.restarted())
    {
        coins.clear();
        obj_manager = std::make_unique<ObjectManager>(&window_);
        gracz->resetRound();
        enemy->resetRound();
        menu.reset();
        timer = 0.f;
    }
    if (menu.lobbie_mode() && coins.size() < 10)
        ensure_lobby_coins();
}

int Game::run(int smoke_frames)
{
    if (!window_.isOpen())
    {
        std::cerr << "Builder Panic: could not open the window\n";
        return 1;
    }

    sf::Music music;
    const std::string music_path = assetPath("Audio/muzyczka.wav");
    const bool has_music = music.openFromFile(music_path);
    if (!has_music)
        std::cerr << "Builder Panic: music disabled (" << music_path << ")\n";
    else
    {
        music.setLoop(true);
        music.setVolume(30);
        music.play();
    }

    if (smoke_frames > 0)
        window_.setFramerateLimit(0);
    else
        window_.setFramerateLimit(60);

    int frames = 0;
    while (window_.isOpen())
    {
        sf::Time elapsed = clock.restart();
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();
            menu.menu_event(event, *gracz, *enemy);
            this->restart();
        }

        float dt = elapsed.asSeconds();
        if (smoke_frames > 0)
            dt = 1.f / 60.f;
        else if (dt > 0.05f)
            dt = 0.05f;

        this->update(dt);
        if (obj_manager->full_board() && !menu.paused())
        {
            obj_manager->addScore(*gracz, *enemy);
            menu.end_update(*gracz, *enemy);
        }
        window_.clear(sf::Color::Black);
        this->draw();
        window_.display();

        if (smoke_frames > 0 && ++frames >= smoke_frames)
            window_.close();
    }

    if (smoke_frames > 0)
    {
        const sf::Vector2f ep = enemy->getPosition();
        const sf::Vector2f pp = gracz->getPosition();
        int painted = 0;
        for (const auto &row : obj_manager->getBoard())
        {
            for (const auto &col : row.second)
            {
                if (col.second->getColor_Object() != Object::Color::Default)
                    ++painted;
            }
        }
        std::cerr << "smoke frames=" << frames
                  << " coins=" << coins.size()
                  << " painted=" << painted
                  << " enemy=(" << ep.x << "," << ep.y << ") score=" << enemy->getScore()
                  << " player=(" << pp.x << "," << pp.y << ") score=" << gracz->getScore()
                  << "\n";
    }
    return 0;
}

Game::Game(const float &w, const float &h)
    : window_(sf::VideoMode(static_cast<unsigned>(w), static_cast<unsigned>(h)), "Bulding Panic"),
      scena(&window_), menu(&window_)
{
    coins.reserve(16);
    obj_manager = std::make_unique<ObjectManager>(&window_);
    gracz = std::make_unique<Player>();
    enemy = std::make_unique<SmartEnemy>(sf::Vector2f(1025.f, 250.f));
    const std::string coins_path = assetPath("Audio/coins.wav");
    if (!buffer.loadFromFile(coins_path))
        std::cerr << "Builder Panic: coin sound disabled (" << coins_path << ")\n";
    else
    {
        coin_effect.setBuffer(buffer);
        coin_sound_ = true;
    }
    ensure_lobby_coins();
}
