#ifndef BOARD_H
#define BOARD_H
#include "Board.h"
#endif

#ifndef PIECETYPE
#define PIECETYPE
#include "piecetype.cpp"
#endif

#include <iostream>


Board::Board()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) {
            squares[i][j] = PieceType::NONE;
        }
    }
}

Board::~Board()
{

}

bool Board::IsWinner(PieceType piece)
{
    bool isWinner = false;

    int i = 0;
    while(i < 8 && !isWinner)
    {
        if(SquareIsPiece(winnerVectors[i][0], piece)
            && SquareIsPiece(winnerVectors[i][1], piece)
            && SquareIsPiece(winnerVectors[i][2], piece))
        {
            isWinner = true;
        }
        i++;
    }

    return isWinner;
}

void Board::PlacePiece(PieceType piece, int square)
{
    int row = SquareToRow(square);
    int column = SquareToColumn(square);

    squares[row][column] = piece;
}

int Board::SquareToRow(int square)
{
    return (square - 1) / 3;
}

int Board::SquareToColumn(int square)
{
    return (square  - 1) % 3;
}

bool Board::IsDrawnGame()
{
    int squaresAvailable = 0;

    for(int i = 1; i <= 9; i++)
    {
        int row = SquareToRow(i);
        int column = SquareToColumn(i);

        if(squares[row][column] == PieceType::NONE)
        {
            squaresAvailable++;
        }
    }

    return squaresAvailable == 0;
}

bool Board::SquareIsPiece(int square, PieceType piece)
{
    int row = SquareToRow(square);
    int column = SquareToColumn(square);

    return squares[row][column] == piece;
}

PieceType Board::PieceAtLocation(int row, int column)
{
    return squares[row][column];
}