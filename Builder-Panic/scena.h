#ifndef SCENA_H
#define SCENA_H
#include "objectmanager.h"

class Scena
{
public:
    Scena(sf::RenderWindow *window);
    virtual ~Scena() = default;
    void draw();
    const std::vector<std::unique_ptr<sf::Sprite>> &getVec(const std::string &key);

private:
    sf::Texture texture;
    sf::RenderWindow *window_;
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
};

#endif // SCENA_H
