#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "object.h"
#include "player.h"
class Game;
class ObjectManager
{
private:
    float points;
public:
    void add(const int &m,const int &n,std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color);
    void Paint(const sf::RenderWindow &window, const sf::Event &event);
    void Paint(const Player &gracz);
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
    bool full_board(){
        bool is_full = false;
        for(const auto &el : board_){
            for(const auto &v : el.second){
                if(v.second->getIntColor() == 0){
                    is_full = true;
                }
            }
        }
        if(is_full){
            return false;
        }
        return true;
    }
    ObjectManager(){}
    virtual ~ObjectManager(){}
};

#endif // OBJECTMANAGER_H
