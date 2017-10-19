// TestTicTacToeGame.cpp
// Tyler Decker

#include "TestTicTacToeGame.h"
#include <iostream>

// This Macro is used to add a test to the test suite
#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestTicTacToeGame> \
   (testDescription, &TestTicTacToeGame::testName))	  \

void TestTicTacToeGame::setUp() {
  myBoard = new GameBoardTTT();
  myIo = new GameIoTicTacToeText();
  p1 = new TicTacToePlayerHuman('X', myBoard, myIo);
  p2 = new TicTacToePlayerHuman('O', myBoard, myIo);
  myGame = new TicTacToeGame(myIo, myBoard, p1, p2);
  
  sbuf = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  std::cin.clear();
  std::cin.rdbuf(myin.rdbuf());
  
}

void TestTicTacToeGame::tearDown() {
  delete myBoard;
  delete myIo;
  delete p1;
  delete p2;
  delete myGame;
  std::cout.rdbuf(sbuf);
}

CppUnit::Test *TestTicTacToeGame::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestTicTacToeGameCase");
  ADD_TEST(testSetFirstPlayer1, "Ensure that player1 goes first when user selects player 1");
  ADD_TEST(testSetFirstPlayer2, "Ensure that player2 goes first when user selects player 2");
  ADD_TEST(testSwitchTurns, "Ensure that if curretPlayer is 1 that after switchTurns  currentPlayer is player 2");
  ADD_TEST(testPlayAgainYes, "Ensure playAgain returns true when input is \'y\'");
  ADD_TEST(testPlayAgainYes, "Ensure playAgain returns false when input is \'n\'");
  return Tests;
}

void TestTicTacToeGame::testSetFirstPlayer1() { 
  myin << "1\n";
  myGame->setFirstPlayer();
  CPPUNIT_ASSERT_EQUAL('X', myGame->getCurrentPlayerMark());  
}

void TestTicTacToeGame::testSetFirstPlayer2() {
  myin << "2\n";
  myGame->setFirstPlayer();
  CPPUNIT_ASSERT_EQUAL('O', myGame->getCurrentPlayerMark());  
}

void TestTicTacToeGame::testSwitchTurns() {
  myin << "1\n";
  myGame->setFirstPlayer();
  myGame->switchTurns();
  CPPUNIT_ASSERT_EQUAL('O', myGame->getCurrentPlayerMark());
}

void TestTicTacToeGame::testPlayAgainYes() {
  myin <<"y\n";
  CPPUNIT_ASSERT(myGame->playAgain());
}

void TestTicTacToeGame::testPlayAgainNo() {
  myin <<"n\n";
  CPPUNIT_ASSERT_EQUAL(false, myGame->playAgain());
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestTicTacToeGame::suite());
  std::cout << " **** Testing TicTacToeGame Class ****\n";
  runner.run();
  return 0;
}
