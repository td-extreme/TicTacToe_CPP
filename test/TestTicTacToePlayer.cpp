// TestTicTacToePlayer.cpp
// Tyler Decker

#include "TestTicTacToePlayer.h"

#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestTicTacToePlayer> \
   (testDescription, &TestTicTacToePlayer::testName))	  \

void TestTicTacToePlayer::setUp() {
  myBoard.newGame('X', 'Y');
  myIo = new GameIoTicTacToeText();
  myHuman = new TicTacToePlayerHuman('H', &myBoard, myIo);
  myPcEasy = new TicTacToePlayerPcEasy('E', &myBoard, myIo);
  myPcMedium = new TicTacToePlayerPcMedium('M', &myBoard, myIo);
  myPcHard = new TicTacToePlayerPcHard('H', &myBoard, myIo);
}

void TestTicTacToePlayer::tearDown() {
  delete myIo;
  delete myHuman;
  delete myPcEasy;
  delete myPcMedium;
  delete myPcHard;
}

CppUnit::Test *TestTicTacToePlayer::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestTicTacToePlayerCase");

  ADD_TEST(testReturnGetTypeHuman, "Verify that getType returns \"Human\" if Player is Human");
  ADD_TEST(testReturnGetTypePcEasy, "Verify that getType returns \"PC Easy\" if Player is PcEasy");
  ADD_TEST(testReturnGetTypePcMedium, "Verify that getType returns \"PC Medium\" if Player is PcMedium");
  ADD_TEST(testReturnGetTypePcHard, "Verify that getType returns \"PC Hard\" if Player is PcHard");
  ADD_TEST(testGetMark, "Verify that getMark returns \'H\' if mark is H");

  ADD_TEST(testGetRandomMoveBlankBoard, "Verify getRandomMove returns 1 when empty board is empty and srand is seeded to 1");
  ADD_TEST(testGetRandomMoveCenterClosed, "Verify getRandomMove returns 8 when center space is taken on board and srand is seeded to 1");
  ADD_TEST(testGetRandomMoveOneSpaceLeft, "Verify getRandomMove returns 0 when it is the only space left");
  ADD_TEST(testGetRandomMoveFullBoard, "Verify getRandomMove returns -1 when board is full");
  ADD_TEST(testGetCornerMoveBlankBoard, "Verify getCornerMove return 8 when board is empty");
  ADD_TEST(testGetCornerMoveTopLeftClosed, "Verify getCornerMove return 6 when top left corner is unavaliable");
  ADD_TEST(testGetCornerMoveOneSpaceLeft, "Verify getCornerMove return 0 when only top left corner is left");
  ADD_TEST(testGetCornerMoveFullBoard, "Verify getCornerMove return -1 when board is empty");
  ADD_TEST(testGetBestMoveEmptyBoard, "Verify getBestMove returns 4 on an empty board");
  ADD_TEST(testGetBestMoveFullBoard, "Verify getBestMove returns -1 on a full board");
  ADD_TEST(testWillMoveWinRow, "Verify that willMoveWin returns true if the move makes a win happen in row 1");
  ADD_TEST(testWillMoveWinCol, "Verify that willMoveWin returns true if the move makes a win happen in col 1");
  ADD_TEST(testWillMoveWinDiagonal, "Verify that willMoveWin returns true if the move makes a win happen diagonal");
  ADD_TEST(testWillMoveWinFalse, "Verify that willMoveWin returns false if the move doesn't win");
  ADD_TEST(testGetOpponentMark, "Verify that getOpponentMark returns \'Y\' when player is \'X\'");
  
  return Tests;
}

void TestTicTacToePlayer::testReturnGetTypeHuman() {
  std::string test_ = "Human";
  CPPUNIT_ASSERT_EQUAL(test_, myHuman->getType());
}

void TestTicTacToePlayer::testReturnGetTypePcEasy() {
  std::string test_ = "PC Easy";
  CPPUNIT_ASSERT_EQUAL(test_, myPcEasy->getType());
}

void TestTicTacToePlayer::testReturnGetTypePcMedium() {
  std::string test_ = "PC Medium";
  CPPUNIT_ASSERT_EQUAL(test_, myPcMedium->getType());
}

void TestTicTacToePlayer::testReturnGetTypePcHard() {
  std::string test_ = "PC Hard";
  CPPUNIT_ASSERT_EQUAL(test_, myPcHard->getType());
}

void TestTicTacToePlayer::testGetMark() {
  CPPUNIT_ASSERT_EQUAL('H', myHuman->getMark());
}

void TestTicTacToePlayer::testGetRandomMoveBlankBoard() {
  srand(1);
  CPPUNIT_ASSERT_EQUAL(1, myPcEasy->getRandomMove());
}

void TestTicTacToePlayer::testGetRandomMoveCenterClosed() {
  myBoard.playMove(4, 'O');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(8, myPcEasy->getRandomMove());
}

void TestTicTacToePlayer::testGetRandomMoveOneSpaceLeft() {
  myBoard.playMove(1, 'X');
  myBoard.playMove(2, 'X');
  myBoard.playMove(3, 'X');
  myBoard.playMove(4, 'X');
  myBoard.playMove(5, 'X');
  myBoard.playMove(6, 'X');
  myBoard.playMove(7, 'X');
  myBoard.playMove(8, 'X');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(0, myPcEasy->getRandomMove());
}

void TestTicTacToePlayer::testGetRandomMoveFullBoard() {
  myBoard.clear('X');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(-1, myPcEasy->getRandomMove());
}

void TestTicTacToePlayer::testGetCornerMoveBlankBoard() {
  srand(1);
  CPPUNIT_ASSERT_EQUAL(8, myPcEasy->getCornerMove());
}

void TestTicTacToePlayer::testGetCornerMoveTopLeftClosed() {
  myBoard.playMove(0, 'X');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(6, myPcEasy->getCornerMove());
}

void TestTicTacToePlayer::testGetCornerMoveOneSpaceLeft() {
  myBoard.playMove(2, 'X');
  myBoard.playMove(6, 'X');
  myBoard.playMove(8, 'X');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(0, myPcEasy->getCornerMove());
}

void TestTicTacToePlayer::testGetCornerMoveFullBoard() {
  myBoard.playMove(0, 'X');
  myBoard.playMove(2, 'X');
  myBoard.playMove(6, 'X');
  myBoard.playMove(8, 'X');
  srand(1);
  CPPUNIT_ASSERT_EQUAL(-1, myPcEasy->getCornerMove());
}

void TestTicTacToePlayer::testGetBestMoveEmptyBoard() {
  CPPUNIT_ASSERT_EQUAL(4, myPcEasy->getBestMove());	       
}

void TestTicTacToePlayer::testGetBestMoveFullBoard() {
  myBoard.clear('X');
  CPPUNIT_ASSERT_EQUAL(-1, myPcEasy->getBestMove());	       
}

void TestTicTacToePlayer::testWillMoveWinRow() {
  myBoard.playMove(0, 'X');
  myBoard.playMove(1, 'X');
  CPPUNIT_ASSERT(myPcEasy->willMoveWin(2, 'X'));
}

void TestTicTacToePlayer::testWillMoveWinCol() {
  myBoard.playMove(0, 'X');
  myBoard.playMove(3, 'X');
  CPPUNIT_ASSERT(myPcEasy->willMoveWin(6, 'X'));
}

void TestTicTacToePlayer::testWillMoveWinDiagonal() {
  myBoard.playMove(0, 'X');
  myBoard.playMove(4, 'X');
  CPPUNIT_ASSERT(myPcEasy->willMoveWin(8, 'X'));
}

void TestTicTacToePlayer::testWillMoveWinFalse() {
  CPPUNIT_ASSERT_EQUAL(false, myPcEasy->willMoveWin(8, 'X'));
}

void TestTicTacToePlayer::testGetOpponentMark() {
  delete myHuman;
  delete myPcEasy;
  myHuman = new TicTacToePlayerHuman('X', &myBoard, myIo);
  myPcEasy = new TicTacToePlayerPcEasy('O', &myBoard, myIo);
  myBoard.newGame('X', 'Y');
  CPPUNIT_ASSERT_EQUAL('Y', myHuman->getOpponentMark());
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestTicTacToePlayer::suite());
  runner.run();
  return 0;
}
