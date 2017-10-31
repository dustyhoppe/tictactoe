#ifndef GAME_H
#define GAME_H
#include "game.h"
#endif

#include <iostream>


Game::Game()
{
    board = new Board();
    pieceToMove = PieceType::X;
};

Game::~Game()
{
    delete board;
}

void Game::Start()
{
    PrintGameStart();

    bool gameContinue = true;
    while(gameContinue)
    {
        PromptNextPieceMove(pieceToMove);

        if(board->IsWinner(pieceToMove))
        {
            PrintWinnerMessage(pieceToMove);
            gameContinue = false;
        } 
        else if(board->IsDrawnGame()) 
        {
            PrintDrawnGameMessage();
            gameContinue = false;
        } 
        else 
        {
            EndTurn();
        }
    }
}

void Game::PrintGameStart()
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "Welcome to Tic Tac Toe" << std::endl << std::endl;
}

void Game::PromptNextPieceMove(PieceType piece)
{
    char charToMove = board->PieceTypeToChar(piece);

    std::cout << "Player " << charToMove << " it is your move" << std::endl;
    std::cout << "Enter your square number now ..." << std::endl;

    board->PrintPromptBoard();

    int squareToPlay = 0;
    std::cin >> squareToPlay;

    std::cout << std::endl <<  charToMove << "'s select " << squareToPlay << std::endl;
    board->PlacePiece(piece, squareToPlay);

    board->Print();
    std::cout << std::endl;
}

void Game::EndTurn()
{
    if(pieceToMove == PieceType::X)
    {
        pieceToMove = PieceType::O;
    } else if(pieceToMove == PieceType::O) {
        pieceToMove = PieceType::X;
    }
    else{
        throw new std::exception();
    }
}

void Game::PrintWinnerMessage(PieceType piece)
{
    char winner = board->PieceTypeToChar(piece);

    std::cout << "CONGRATS! " << winner << "'s have achieved 3 in-a-row!" << std::endl << std::endl;
}

void Game::PrintDrawnGameMessage()
{
    std::cout << std::endl << "Sorry, the game has been drawn. Please try again!" << std::endl << std::endl;
}