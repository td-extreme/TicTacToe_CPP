// GameBoardTTT.h
// Tyler Decker

#ifndef _GAMETICTACTOE_H
#define _GAMETICTACTOE_H

#include <vector>
#include "GameBoard2D.h"

class GameBoardTTT {

 protected:
  GameBoard2D<char> board;    
  char playerMark1;
  char playerMark2;

 public:

  enum boardState  { PLAYING = 'P', TIED = 'T', WON = 'W' };
  GameBoardTTT();
  GameBoardTTT(const GameBoardTTT &other);
  GameBoardTTT & operator= (const GameBoardTTT & other);
  void newGame(char player1, char player2);
  void clear(char mark);
  bool validMove(int space);
  bool playMove(int space, char playerMark);
  void setSpace(int space, char playerMark);
  boardState getBoardState();
  bool checkForWinner();
  bool checkForWinner(char &winner);
  char getPlayer1();
  char getPlayer2();
  std::vector<int> getAvailableSpaces();
  char getSpace(int space) { return board.getSpace(space); }
  std::string toString() { return board.toString(); }
};
#endif
