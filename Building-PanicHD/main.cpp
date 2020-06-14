#include "game.h"

int main()
{
    srand(time(NULL));
    Game game(1920, 1080);
    game.run();
    return 0;
}
