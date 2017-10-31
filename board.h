#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif

class Board
{
public:

    Board ();
    ~Board();

    void Print();
    void PrintPromptBoard();
    bool IsWinner(PieceType piece);
    char PieceTypeToChar(PieceType piece);
    void PlacePiece(PieceType piece, int square);
    bool IsDrawnGame();

private:
    PieceType squares[3][3];
    int winnerVectors [8][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }, 
        { 1, 4, 7 },
        { 2, 5, 8 },
        { 3, 6, 9 },
        { 1, 5, 9 },
        { 7, 5, 3 }
    };

    int SquareToRow(int square);
    int SquareToColumn(int square);
    bool SquareIsPiece(int square, PieceType piece);
};