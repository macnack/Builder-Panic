#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <object.h>
#include <game.h>
class ObjectManager
{
public:
    void add(const int &m,const int &n,std::unique_ptr<Object> block_);
    void Reverse(const int &m,const int &n, const Object::Color &color);
    void Paint(const Game &game);
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
    //count points
    ObjectManager(){}
    virtual ~ObjectManager(){}
};

#endif // OBJECTMANAGER_H
