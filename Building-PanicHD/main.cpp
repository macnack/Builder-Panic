#include "game.h"

#include <cstdlib>
#include <ctime>
#include <string>

int main(int argc, char **argv)
{
    int smoke = 0;
    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "--smoke" && i + 1 < argc)
            smoke = std::atoi(argv[++i]);
    }
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Game game(1920, 1080);
    return game.run(smoke);
}
