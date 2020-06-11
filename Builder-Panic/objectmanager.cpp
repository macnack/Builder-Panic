#include "objectmanager.h"

void ObjectManager::add(const int &m, const int &n, std::unique_ptr<Object> block_){
    board_.insert(make_pair(m, std::map<int,std::unique_ptr<Object>>()));
    board_[m].insert(make_pair(n, std::move(block_)));
}

void ObjectManager::Reverse(const int &m, const int &n, const Object::Color &color){
    int Intcolor = static_cast<int>(color);
    board_[m][n]->SetFill();
    if(board_[m][n]->can_change()){
        board_[m][n]->Paint(color);
        bool reverse = false;
        for(int i = n; i < 8 ; i++){ // to left
            if(board_[m][i]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[m][i]->getIntColor() == 0){
                reverse = false;
                break;
            }
            if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
                for(int k = n; k < i; k++){
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
                reverse = false;
                break;
            }
            if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
                for(int k = n; k > i ; k--){
                    board_[m][k]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m; i >= 0 ; i--){ // up
            if(board_[i][n]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][n]->getIntColor() == 0){
                reverse = false;
                break;
            }
            if(board_[i][n]->getIntColor() == Intcolor && reverse == true){
                for(int k = m; k > i; k--){
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for(int i = m; i < 4 ; i++){ // down
            if(board_[i][n]->getIntColor() == -Intcolor && reverse == false){
                reverse = true;
            }
            else if(board_[i][n]->getIntColor() == 0){
                reverse = false;
                break;
            }
            if(board_[i][n]->getIntColor() == Intcolor && reverse == true){
                for(int k = m; k < i; k++){
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
                reverse = false;
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m, l = n; k < i && l < j; l++ && k++ ){
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
                reverse = false;
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m, l = n; k > i && l > j; l-- && k-- ){
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
                reverse = false;
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m, l = n; k < i && l > j; l-- && k++ ){
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
                reverse = false;
                break;
            }
            if( board_[i][j]->getIntColor() == Intcolor && reverse == true){
                for(int k = m, l = n; k > i && l < j; l++ && k-- ){
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
    }
}

const std::map<int, std::map<int, std::unique_ptr<Object> > > &ObjectManager::getBoard(){
    return board_;
}

void ObjectManager::Paint(const sf::RenderWindow &window, const sf::Event &event){
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    std::cerr << "XY M : " << mouse_pos.x << " y : " << mouse_pos.y << std::endl;
    for(auto &bd : board_){
        for(auto &bd_el : bd.second){
            if(bd_el.second->getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                if(event.mouseButton.button == sf::Mouse::Left){
                    bd_el.second->Paint(Object::Color::Player);
                }
                if(event.mouseButton.button == sf::Mouse::Right){
                    bd_el.second->Paint(Object::Color::Enemy);
                }
            }
        }
    }
}
//&& bd_el.second->getGlobalBounds().contains(playerBounds.left+playerBounds.width,playerBounds.top+playerBounds.height)
void ObjectManager::Paint(const Player &gracz)
{
    sf::FloatRect playerBounds = gracz.getGlobalBounds();
    for(auto &bd : board_){
        int m = bd.first;
        for(auto &bd_el : bd.second){
            if(bd_el.second->getGlobalBounds().contains(playerBounds.left+playerBounds.width/2.0, playerBounds.top+playerBounds.height - 10)
/*&& bd_el.second->getGlobalBounds().contains(playerBounds.left, playerBounds.top+playerBounds.height - 10)*/){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                    int n = bd_el.first;
                    this->Reverse(m, n, Object::Color::Player );
                }
            }
        }
    }
}

void ObjectManager::Paint(const Enemy &enemy)
{
    sf::FloatRect playerBounds = enemy.getGlobalBounds();
    for(auto &bd : board_){
        int m = bd.first;
        for(auto &bd_el : bd.second){
            if(bd_el.second->getGlobalBounds().contains(playerBounds.left+playerBounds.width/2.0, playerBounds.top+playerBounds.height - 10)
                    && bd_el.second->getGlobalBounds().contains(playerBounds.left, playerBounds.top+playerBounds.height - 10)){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
                    int n = bd_el.first;
                    this->Reverse(m, n, Object::Color::Enemy );
                }
            }
        }
    }
}

bool ObjectManager::full_board(){
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

void ObjectManager::draw()
{
    for (const auto &el : board_)//obj_mangaer->draw(window_)
    {
        for (const auto &v : el.second)
        {
            window_->draw(*v.second);
        }
    }
}

ObjectManager::ObjectManager(sf::RenderWindow *window) : window_(window){
    if (!texture.loadFromFile("Texture/Dungeons Walls.png"))
    {
        throw("Could not load texture 'Dungeons Walls'");
    }
    texture.setRepeated(true);
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
