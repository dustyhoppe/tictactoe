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

void Board::PrintPromptBoard()
{
    std::cout << " -------------" << std::endl;

    for(int i = 0; i < 3; i++)
    {
        std::cout << " | ";
        for(int j = 1; j <= 3; j++)
        {
            std::cout << ((i * 3) + j) << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << " -------------" << std::endl;
}

Board::~Board()
{

}

void Board::Print()
{
    std::cout << " -------------" << std::endl;

    for(int i = 0; i < 3; i++)
    {
        std::cout << " | ";
        for(int j = 0; j < 3; j++)
        {
            char val = PieceTypeToChar(squares[i][j]);

            std::cout << val << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << " -------------" << std::endl;
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

char Board::PieceTypeToChar(PieceType piece)
{
    if(piece == PieceType::X)
    {
        return 'X';
    }
    else if(piece == PieceType::O)
    {
        return 'O';
    }
    else
    {
        return '-';
    }
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