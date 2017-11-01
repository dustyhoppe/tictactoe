#ifndef BOARD_H
#define BOARD_H
#include "board.h"
#endif

#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "console.h"
#endif

class Game
{

public:
    Game();
    ~Game();

    void Play();

private:
    Board *board;
    Console *console;
    PieceType pieceToMove;

    void PromptNextPieceMove(PieceType piece);
    void EndTurn();
};