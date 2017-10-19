// GameBoardTTT.h
// Tyler Decker

#include "GameBoardTTT.h"

GameBoardTTT::GameBoardTTT() : board(3, 3) {
  playerMark1 = 'X';
  playerMark2 = 'Y';
  clear(' '); 
}

GameBoardTTT::GameBoardTTT(const GameBoardTTT &other) : board(other.board) {}

GameBoardTTT & GameBoardTTT::operator= (const GameBoardTTT &other) {
  if (this == &other)
    return *this;
  this->board = other.board;
 
  return *this;  
}

void GameBoardTTT::newGame(char player1, char player2) {
  playerMark1 = player1;
  playerMark2 = player2;
  clear(' ');
}

void GameBoardTTT::clear(char mark) {
  board.clear(mark);
}

bool GameBoardTTT::playMove(int space, char playerMark) {
  if (validMove(space)) {
    board.setSpace(space, playerMark);
    return true;
  }
  return false;
}

void GameBoardTTT::setSpace(int space, char playerMark) {
  board.setSpace(space, playerMark);
}

bool GameBoardTTT::validMove(int space) {
  if (space < 0 || space > 8)
    return false;
  if (board.getSpace(space) == ' ') { return true; }
   return false;
}

GameBoardTTT::boardState GameBoardTTT::getBoardState() {
  char winner_ = ' ';
  if (checkForWinner(winner_) == true) 
    return WON;
  if (getAvailableSpaces().size() == 0) 
    return TIED;

  return PLAYING;
}

bool GameBoardTTT::checkForWinner() {
  char unReturned_ = ' ';
  return checkForWinner(unReturned_);
}

bool GameBoardTTT::checkForWinner(char &winner) {
  for (int i = 0; i <= 2; ++i) {
    if (board.getSpace(i, 0) == board.getSpace(i, 1) &&
      	board.getSpace(i, 0) == board.getSpace(i, 2) &&
	      board.getSpace(i, 0) != ' ') {
      winner = board.getSpace(i, 0);
      return true;
    }
    if (board.getSpace(0, i) == board.getSpace(1, i) &&
      	board.getSpace(0, i) == board.getSpace(2, i) &&
      	board.getSpace(0, i) != ' ') {
      winner = board.getSpace(0, i);
      return true;
    }
  }
  if (board.getSpace(4) != ' ') {
    if (board.getSpace(0) == board.getSpace(4) &&
	board.getSpace(8) == board.getSpace(4)) {
      winner = board.getSpace(4);
      return true;
    }
    if (board.getSpace(2) == board.getSpace(4) &&
	board.getSpace(6) == board.getSpace(4)) {
      winner = board.getSpace(4);
      return true;
    }
  }
  winner = ' ';
  return false;
}

char GameBoardTTT::getPlayer1() {
  return playerMark1;
}

char GameBoardTTT::getPlayer2() {
  return playerMark2;
}

std::vector<int> GameBoardTTT::getAvailableSpaces() {
  std::vector<int> availableSpaces_;
  int spot_;
  for (int i = 0; i < 9; ++i) {
    if (getSpace(i) == ' ')
      availableSpaces_.push_back(i);
  }
  return availableSpaces_;
}

