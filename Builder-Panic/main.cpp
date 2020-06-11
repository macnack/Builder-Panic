#include "game.h"

int main()
{
    srand(time(NULL));
    float maxHeight = 610.0f; //600
    float maxWidth = 800.0f;  //800
    Game game(maxWidth, maxHeight);
    game.run();
    return 0;
}
