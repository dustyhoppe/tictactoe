#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif

class Board
{
public:

    Board ();
    ~Board();

    bool IsWinner(PieceType piece);
    void PlacePiece(PieceType piece, int square);
    PieceType PieceAtLocation(int row, int column);
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