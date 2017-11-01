#ifndef BOARD_H
#define BOARD_H
#include "board.h"
#endif

#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif


class Console
{
public:
    Console();
    ~Console();
    void PrintBoard(Board *board);
    void PrintPromptBoard();
    void PrintGameStart();
    void PrintDrawnGameMessage();
    void PrintWinnerMessage(PieceType piece);
    void PromptPlayerToMove(PieceType piece);
    int PromptSquareToPlay(PieceType piece);

private:
    char PieceTypeToChar(PieceType piece);
};