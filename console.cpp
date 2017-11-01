#ifndef CONSOLE_H
#define CONSOLE_H
#include "console.h"
#endif

#include <iostream>

Console::Console()  { }
Console::~Console() { }

void Console::PrintGameStart()
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "Welcome to Tic Tac Toe" << std::endl << std::endl;
}

void Console::PrintBoard(Board* board)
{
    std::cout << " -------------" << std::endl;
    
        for(int i = 0; i < 3; i++)
        {
            std::cout << " | ";
            for(int j = 0; j < 3; j++)
            {
                PieceType piece = board->PieceAtLocation(i, j);
                char val = PieceTypeToChar(piece);
    
                std::cout << val << " | ";
            }
            std::cout << std::endl;
        }
    
        std::cout << " -------------" << std::endl << std::endl;
}

void Console::PrintPromptBoard()
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

void Console::PrintDrawnGameMessage()
{
    std::cout << std::endl << "Sorry, the game has been drawn. Please try again!" << std::endl << std::endl;
}

void Console::PrintWinnerMessage(PieceType piece)
{
    char winner = PieceTypeToChar(piece);

    std::cout << "CONGRATS! " << winner << "'s have achieved 3 in-a-row!" << std::endl << std::endl;
}

void Console::PromptPlayerToMove(PieceType piece)
{
    char charToMove = PieceTypeToChar(piece);
    
    std::cout << "Player " << charToMove << " it is your move" << std::endl;
    std::cout << "Enter your square number now ..." << std::endl;
}

int Console::PromptSquareToPlay(PieceType piece)
{
    char charToMove = PieceTypeToChar(piece);
    int squareToPlay;

    std::cin >> squareToPlay;
    
    std::cout << std::endl <<  charToMove << "'s select " << squareToPlay << std::endl;
    
    return squareToPlay;
}

char Console::PieceTypeToChar(PieceType piece)
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