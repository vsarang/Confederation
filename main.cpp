#include "game.h"
#include "gamestatestart.h"

int main (int argc, char* args[]) {
    Game game;
    game.pushState(new GameStateStart(&game));
    game.gameLoop();
    return 0;
}
