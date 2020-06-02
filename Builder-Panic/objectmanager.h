#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <object.h>
#include <game.h>
class ObjectManager
{
public:
    void add(int m, int n, std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color){
        int Intcolor = static_cast<int>(color);
        board_[m][n]->Paint(color);
        bool reverse = false;
        for(int i = n; i < 8 ; i++){ // to left
            if(board_[m][i]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[m][i]->getIntColor() == 0){
                std::cerr << "Blok z lewej" << std::endl;
                break;
            }
            if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
                for(int k = n+1; k < i; k++){
                    board_[m][k]->Paint(color);
                }
                break;//or continue?
            }
        }
        for(int i = n; i >= 0 ; i--){ // to right
            if(board_[m][i]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[m][i]->getIntColor() == 0){
                std::cerr << "Blok z prawej" << std::endl;
                break;
            }
            if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
                for(int k = n-1; k > i ; k--){
                    board_[m][k]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m; i >= 0 ; i--){ // up
            if(board_[i][n]->getIntColor() == -Intcolor && reverse == false){
                std::cout << "kolorek up" << std::endl;
                reverse = true;
            }
            else if(board_[i][n]->getIntColor() == 0){
                std::cerr << "Blok z gory" << std::endl;
                break;
            }
            if(board_[i][n]->getIntColor() == Intcolor && reverse == true){
                for(int k = m-1; k > i; k--){
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m; i < 4 ; i++){ // down
            if(board_[i][n]->getIntColor() == -Intcolor && reverse == false){
                std::cout << "kolorek" << std::endl;
                reverse = true;
            }
            else if(board_[i][n]->getIntColor() == 0){
                std::cerr << "Blok z dolu" << std::endl;
                break;
            }
            if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
                for(int k = m+1; k < i; k++){
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m, j = n; i < 4 && j < 8 ;j++ && i++){ // \ from r to l
            if( board_[i][j]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][j]->getIntColor() == 0){
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m+1, l = n+1; k < i && l < j; l++ && k++ ){
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m, j = n; i >= 0 && j >= 0 ; j-- && i--){ // \ from l to r
            if( board_[i][j]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][j]->getIntColor() == 0){
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m-1, l = n-1; k > i && l > j; l-- && k-- ){
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m, j = n; i < 4 && j >= 0 ;j-- && i++){ // / left to right
            if( board_[i][j]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][j]->getIntColor() == 0){
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m+1, l = n-1; k < i && l > j; l-- && k++ ){
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m, j = n; i >= 0 && j < 8 ;j++ && i--){ // / left to right
            if( board_[i][j]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][j]->getIntColor() == 0){
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m-1, l = n+1; k > i && l < j; l++ && k-- ){
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
    }
    void Paint(const Game &game){
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(game.window_);
        for(auto &bd : board_){
            int m = bd.first;
            for(auto &bd_el : bd.second){
            if(bd_el.second->getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                if(game.event.mouseButton.button == sf::Mouse::Left){
                    int n = bd_el.first;
                    //bd_el.second->Paint(Object::Color::Player);
                    this->Reverse(m, n, Object::Color::Player );
                }
                if(game.event.mouseButton.button == sf::Mouse::Right){
                    int n = bd_el.first;
                    this->Reverse(m, n, Object::Color::Enemy);
                    //bd_el.second->Paint(Object::Color::Enemy);
                }
            }
        }
    }
    }
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
    ObjectManager(){}
    virtual ~ObjectManager(){}
};

#endif // OBJECTMANAGER_H
