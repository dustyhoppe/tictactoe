#ifndef BOARD_H
#define BOARD_H
#include "Board.h"
#endif

#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif

class Game
{

public:
    Game();
    ~Game();

    void Start();

private:
    Board *board;
    PieceType pieceToMove;

    void PrintGameStart();
    void PromptNextPieceMove(PieceType piece);
    void PrintWinnerMessage(PieceType piece);
    void PrintDrawnGameMessage();
    void EndTurn();
};