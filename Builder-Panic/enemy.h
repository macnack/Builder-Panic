#ifndef ENEMY_H
#define ENEMY_H


class Player
{
    //hp
    //attack
    //speed
    //platform
public:
    Player();
    //move
    //painting
    //attack

};

#endif // ENEMY_H
/*
void ObjectManager::Reverse(const int &m, const int &n, const Object::Color &color){
    int Intcolor = static_cast<int>(color);
    board_[m][n]->Paint(color);
    bool reverse = false;
    for(int i = n; i < 8 ; i++){ // to left
        if(board_[m][i]->getIntColor() == -Intcolor && reverse == false){
            reverse = true;
        }
        else if(board_[m][i]->getIntColor() == 0 || (board_[m][i]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[m][i]->getIntColor() == 0 || (board_[m][i]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[i][n]->getIntColor() == 0 || (board_[i][n]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[i][n]->getIntColor() == 0 || (board_[i][n]->getIntColor() == Intcolor && reverse == false)){
            break;
        }
        if(board_[m][i]->getIntColor() == Intcolor && reverse == true){
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
        else if(board_[i][j]->getIntColor() == 0 || (board_[i][j]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[i][j]->getIntColor() == 0 || (board_[i][j]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[i][j]->getIntColor() == 0 || (board_[i][j]->getIntColor() == Intcolor && reverse == false)){
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
        else if(board_[i][j]->getIntColor() == 0 || (board_[i][j]->getIntColor() == Intcolor && reverse == false)){
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
*/
