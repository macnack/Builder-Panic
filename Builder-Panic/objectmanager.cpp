#include "objectmanager.h"

void ObjectManager::add(int m, int n, std::unique_ptr<Object> block_){
    board_.insert(make_pair(m, std::map<int,std::unique_ptr<Object>>()));
    board_[m].insert(make_pair(n, std::move(block_)));
}
