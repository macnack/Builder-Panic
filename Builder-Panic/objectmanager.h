#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "object.h"
#include "player.h"
#include "enemy.h"

class Game;
class ObjectManager
{
private:
    float points;
    double x = 0.f;
    double y = 10.f;
    void add(const int &m,const int &n,std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color);
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
public:
    const std::map<int , std::map<int, std::unique_ptr<Object>>> &getBoard(){
        return board_;
    }
    void Paint(const Player &gracz);
    void Paint(const sf::RenderWindow &window, const sf::Event &event);
    void Paint(const Enemy &enemy);
    bool full_board();
    ObjectManager(const sf::Texture &texture){
        for(int i = 0 ; i < 8; i++){
            for(int k =0; k < 4; k++){
                std::unique_ptr<Object> block_ = std::make_unique<Object>
                        (sf::Vector2f(x,y),sf::FloatRect(0,0,91,140),texture);
                //Sceny testowe:
                //wspolrzedne [k][i]
                //scena 1
                //1. lewy  [1][2]
                //2. prawy [2][2]
                //3. lewy  [0][5] : obiekt [2][3] nie powinien zmieniac koloru
                //            if( (k == 1 && i == 3) || (k == 2 && i == 4) || ( k == 0 && i == 2)){
                //                block_->Paint(Object::Color::Enemy);
                //            }
                //            if( (k == 1 && i == 4) || (k == 2 && i == 3) || ( k == 3 && i == 2)){
                //                block_->Paint(Object::Color::Player);
                //            }
                //scena 2:
                //1. lewy  [2][2]
                //2. prawy [1][5]
                //3. prawy [1][6] : obiekt [1][2] nie powinien zmieniac koloru
                //            if( (k == 0 && i == 2) || ( k == 1 && (i == 0 || i == 4 ))){
                //                block_->Paint(Object::Color::Player);
                //            }
                //            if( k==1 && ( i == 1 || i == 2 || i == 3)){
                //                block_->Paint(Object::Color::Enemy);
                //            }
                this->add(k,i,std::move(block_));
                y += 150;
            }
            x += 101.25;
            y = 10.0;
        }
    }
    virtual ~ObjectManager() = default;
};

#endif // OBJECTMANAGER_H
