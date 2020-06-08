#ifndef SCENA_H
#define SCENA_H
#include "objectmanager.h"

class Scena
{
public:
    Scena();
    void draw(sf::RenderWindow &window);
    const std::vector<std::unique_ptr<sf::Sprite>> &getVec(const std::string &key){
        return map[key];
    }
private:
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> map;
};

#endif // SCENA_H
