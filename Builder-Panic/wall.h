#ifndef WALL_H
#define WALL_H
#include "object.h"

class Wall : Object
{
public:
    Wall();
private:

    enum Elevation{
        none = 0,
        one_third,
        two_third,
        full
    };

};

#endif // WALL_H
