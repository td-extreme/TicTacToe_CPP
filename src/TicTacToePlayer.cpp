// TicTacToe.cpp
// Tyler Decker

#include "TicTacToePlayer.h"

TicTacToePlayer::TicTacToePlayer(char mark, GameBoardTTT * gameBoard, GameIoTicTacToe * gameIo) :  mark(mark), myTTT(gameBoard), myIo(gameIo) {
  srand(time(NULL));
}

bool TicTacToePlayer::willMoveWin(int space, char player) {
  bool rtn_ = false;
  myTTT->setSpace(space, player);
  if (myTTT->checkForWinner() == true)
    rtn_ = true;
  myTTT->setSpace(space, ' ');
  return rtn_;
}

char TicTacToePlayer::getOpponentMark() {
  return (mark == myTTT->getPlayer1()) ? myTTT->getPlayer2() : myTTT->getPlayer2();
}

int TicTacToePlayer::getBestMove() {
  if (myTTT->validMove(4))
    return 4;
  std::vector<int> moves_ = myTTT->getAvailableSpaces();
  if (moves_.size() == 0)
    return -1;
  for (int i = 0; i < moves_.size(); ++i) {
    if (willMoveWin(moves_[i], mark))
      return moves_[i];
  }
  for (int i = 0; i <moves_.size(); ++i) {
    if (willMoveWin(moves_[i], getOpponentMark()))
      return moves_[i];
  }
  int spot_;
  if ( (spot_ = getCornerMove()) != -1)
    return spot_;

  int index_ = rand() % moves_.size();
  return moves_[index_];
   
  return -1;
}

int TicTacToePlayer::getCornerMove() {
  std::vector<int> moves_;
  if (myTTT->getSpace(0) == ' ')
    moves_.push_back(0);
  if (myTTT->getSpace(2) == ' ')
    moves_.push_back(2);
  if (myTTT->getSpace(6) == ' ')
    moves_.push_back(6);
  if (myTTT->getSpace(8) == ' ')
    moves_.push_back(8);

  if (moves_.size() == 0)
    return -1;

  return moves_[rand() % moves_.size()];
}

int TicTacToePlayer::getRandomMove() {
  std::vector<int> moves_ = myTTT->getAvailableSpaces();
  if (moves_.size() == 0)
    return -1;
  return moves_[rand() % moves_.size()];
}

int TicTacToePlayerHuman::getMove() {
  return myIo->getHumanMove(*myTTT);
}

int TicTacToePlayerPcEasy::getMove() {
  if (myTTT->getSpace(4) == ' ')
    if (0 == rand() % 2)
      return 4;

  if (getCornerMove() != -1)
    if (0 == rand() % 2)
      return getCornerMove();

  return getRandomMove();
}

int TicTacToePlayerPcMedium::getMove() {
  if (myTTT->getSpace(4) == ' ')
    return 4;
  std::vector<int> moves_ = myTTT->getAvailableSpaces();
  for (int i = 0; i < moves_.size(); ++i) {
    if (willMoveWin(moves_[i], mark) ||
        willMoveWin(moves_[i], getOpponentMark()))
      return moves_[i];
  }
  return getRandomMove();
}

int TicTacToePlayerPcHard::getMove() {
  return getBestMove();
}
