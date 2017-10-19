// TicTacToePlayer.h
// Tyler Decker

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "GameBoardTTT.h"
#include "GameIoTicTacToe.h"
#ifndef _TICTACTOEPLAYER_H
#define _TICTACTOEPLAYER_H

class TicTacToePlayer {
 protected:
  char mark;
  GameBoardTTT * myTTT;
  GameIoTicTacToe * myIo;
 public:
  TicTacToePlayer(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo);
  virtual int getMove() = 0;
  virtual std::string getType() = 0;
  char getMark() { return mark; }
  bool willMoveWin(int space, char player);
  char getOpponentMark();
  int getBestMove();
  int getCornerMove();
  int getRandomMove();
};

class TicTacToePlayerHuman : public TicTacToePlayer {
 public:
 TicTacToePlayerHuman(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo)
   : TicTacToePlayer(mark, gameBoard, gameIo) {}
  virtual int getMove();
  virtual std::string getType() { return "Human"; }
};

class TicTacToePlayerPcEasy : public TicTacToePlayer {
 public:
 TicTacToePlayerPcEasy(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo)
   : TicTacToePlayer(mark, gameBoard, gameIo) {}
  virtual int getMove();
  virtual std::string getType() { return "PC Easy"; }
};

class TicTacToePlayerPcMedium : public TicTacToePlayer {
 public:
 TicTacToePlayerPcMedium(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo)
   : TicTacToePlayer(mark, gameBoard, gameIo) {}
  virtual int getMove();
  virtual std::string getType() { return "PC Medium"; }
};

class TicTacToePlayerPcHard : public TicTacToePlayer {
 public:
 TicTacToePlayerPcHard(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo)
   : TicTacToePlayer(mark, gameBoard, gameIo) {}
 virtual int getMove();
 virtual std::string getType() { return "PC Hard"; }
};
#endif
