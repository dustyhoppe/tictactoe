#ifndef GAME_H
#define GAME_H
#include "game.h"
#endif

#include <iostream>


Game::Game()
{
    board = new Board();
    console = new Console();
    pieceToMove = PieceType::X;
};

Game::~Game()
{
    delete board;
    delete console;
}

void Game::Play()
{
    console->PrintGameStart();

    bool gameContinue = true;
    while(gameContinue)
    {
        PromptNextPieceMove(pieceToMove);

        if(board->IsWinner(pieceToMove))
        {
            console->PrintWinnerMessage(pieceToMove);
            gameContinue = false;
        } 
        else if(board->IsDrawnGame()) 
        {
            console->PrintDrawnGameMessage();
            gameContinue = false;
        } 
        else 
        {
            EndTurn();
        }
    }
}

void Game::PromptNextPieceMove(PieceType piece)
{
    console->PromptPlayerToMove(piece);

    console->PrintPromptBoard();

    board->PlacePiece(piece, console->PromptSquareToPlay(piece));

    console->PrintBoard(board);
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