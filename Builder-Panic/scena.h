#ifndef SCENA_H
#define SCENA_H
#include "objectmanager.h"

class Scena
{
public:
    Scena();
    virtual ~Scena() = default;
    void draw(sf::RenderWindow &window);
    const std::vector<std::unique_ptr<sf::Sprite>> &getVec(const std::string &key);
private:
    sf::Texture texture;
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
    sf::RenderWindow *window_;
};

#endif // SCENA_H
