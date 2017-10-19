// GameIoTicTacToe.h
// Tyler Decker

#ifndef _GAMEIOTICTACTOE_H
#define _GAMEIOTICTACTOE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "GameBoardTTT.h"
#include "GameBoard2D.h"
#include "GameMenu.h"
#include "MoveLog.h"

class GameIoTicTacToe  {
 protected:
  std::streambuf * sbuf;

 public:
  GameIoTicTacToe();
  virtual void clearScreen() = 0;
  virtual void print(GameBoardTTT  gameBoardTTT) = 0;
  virtual void print(int outInt) = 0;
  virtual void print(std::string outString) = 0;
  virtual void print(GameBoard2D<int> gameBoard2D) = 0;
  virtual void print(GameBoard2D<char> gameBoard2D) = 0;
  virtual void printGameOver(GameBoardTTT gameBoard) = 0;
  virtual void printPlayerInfo(char mark1, std::string type1, char mark2, std::string type2) = 0;
  virtual void print(GameMenu menu) = 0;
  virtual void print(MoveLog moveLog) = 0;
  virtual char getInput() = 0;
  virtual char getInput(std::vector<char> choices) = 0;
  virtual int getHumanMove(GameBoardTTT gameBoardTTT) = 0;
  virtual bool getYesNo() = 0;
};

class GameIoTicTacToeText : public GameIoTicTacToe {
 public:
  virtual void clearScreen();
  virtual void print(GameBoardTTT gameBoardTTT);
  virtual void printGameOver(GameBoardTTT gameBoardTTT);
  virtual void print(int outInt);
  virtual void print(std::string outString);
  virtual void print(GameBoard2D<int> gameBoard2D);
  virtual void print(GameBoard2D<char> gameBoard2D);
  virtual void printPlayerInfo(char mark1, std::string type1, char mark2, std::string type2);
  virtual void print(GameMenu menu);
  virtual void print(MoveLog moveLog);
  virtual char getInput();
  virtual char getInput(std::vector<char> choices);
  virtual int getHumanMove(GameBoardTTT gameBoardTTT);
  virtual bool getYesNo();
};
#endif
