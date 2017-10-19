// Tyler Decker
// TicTacToeGame.h
#include <vector>
#include "GameBoard2D.h"
#include "GameBoardTTT.h"
#include "TicTacToePlayer.h"
#include "GameIoTicTacToe.h"
#include "MoveLog.h"

#ifndef _TICTACTOEGAME_H
#define _TICTACTOEGAME_H

class TicTacToeGame {
 private:
  GameBoard2D<char> boardLegend;
  MoveLog myMoveLog;
  GameBoardTTT * myBoard;
  GameIoTicTacToe * myIo;
  TicTacToePlayer * p1;
  TicTacToePlayer * p2;
  TicTacToePlayer * currentPlayer;
  GameMenu menuChoosePlayer;
  
 public:
  TicTacToeGame(GameIoTicTacToe * GameIo, GameBoardTTT * board, TicTacToePlayer * player1, TicTacToePlayer * player2);
  void gameLoop();
  void setFirstPlayer();
  bool playAgain();
  void drawScreen();
  void switchTurns();
  char getCurrentPlayerMark();
};
#endif
