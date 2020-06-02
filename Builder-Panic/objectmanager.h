#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <object.h>

class ObjectManager
{
public:
    ObjectManager();
private:
    std::map<int , std::map<int, std::unique_ptr<Object>>> board_;
};

#endif // OBJECTMANAGER_H
