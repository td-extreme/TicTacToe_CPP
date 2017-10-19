// Tyler Decker
// TicTacToeGame.cpp
#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(GameIoTicTacToe * gameIo, GameBoardTTT * board, TicTacToePlayer * player1, TicTacToePlayer * player2):
  myIo(gameIo), myBoard(board), p1(player1), p2(player2), boardLegend(3, 3), menuChoosePlayer("Who should play first?") {
  for (int i = 0; i < 9; ++i) 
    boardLegend.setSpace(i, i + '1');
  menuChoosePlayer.add("Player 1 goes first");
  menuChoosePlayer.add("Player 2 goes first");
}

void TicTacToeGame::gameLoop() {
  char move_;
  do {
    setFirstPlayer();
    myBoard->newGame(p1->getMark(), p2->getMark());
    myMoveLog.clear();
  
    while (myBoard->getBoardState() == 'P' ) {
      drawScreen();
      move_ = currentPlayer->getMove();
      if (myBoard->playMove(move_, currentPlayer->getMark()))
	myMoveLog.add(move_ + 1, currentPlayer->getMark());
      switchTurns();
    }
  } while ( playAgain());
}

void TicTacToeGame::setFirstPlayer() {
  myIo->clearScreen();
  myIo->printPlayerInfo(p1->getMark(), p1->getType(), p2->getMark(), p2->getType());
      myIo->print(menuChoosePlayer);
    switch(myIo->getInput(menuChoosePlayer.choices())) {
    case '1':
	currentPlayer = p1;
	break;
    case '2':
	currentPlayer = p2;
	break;
    }
}

bool TicTacToeGame::playAgain() {
  drawScreen();
  myIo->printGameOver(* myBoard);
  myIo->print("\nPlay again with same players? ");
  return myIo->getYesNo();
}

void TicTacToeGame::drawScreen() {
  myIo->clearScreen();
  myIo->printPlayerInfo(p1->getMark(), p1->getType(), p2->getMark(), p2->getType());
  myIo->print(boardLegend);
  myIo->print(*myBoard);
  myIo->print(myMoveLog);
}

void TicTacToeGame::switchTurns() {
  currentPlayer = (currentPlayer == p1) ? p2 : p1;
}

char TicTacToeGame::getCurrentPlayerMark() {
  return currentPlayer->getMark();
}
