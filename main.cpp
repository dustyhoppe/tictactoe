#include <iostream>
#ifndef GAME_H
#define GAME_H
#include "Game.h"
#endif

int main(int argc, char ** argv)
{
    Game *game = new Game();

    game->Start();

    return 0;
}