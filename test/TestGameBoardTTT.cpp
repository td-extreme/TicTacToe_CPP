// TestGameBoardTTT.cpp
// Tyler Decker

#include "TestGameBoardTTT.h"

#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestGameBoardTTT>			\
   (testDescription, &TestGameBoardTTT::testName))		\

void TestGameBoardTTT::setUp() { 
  testBoardTTT = new GameBoardTTT();
}
void TestGameBoardTTT::tearDown() { 
  delete testBoardTTT;
}

CppUnit::Test *TestGameBoardTTT::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestGameBoardTTTCase");
  
  ADD_TEST(testCopyConstructor, "Verify that deep copy occurs on board with Copy Consturctor");
  ADD_TEST(testAssignmentOperator, "Verify that deep copy occurs on board with Assignement Operator");
  ADD_TEST(testGetPlayer1, "Verify getPlayer1 returns \'O\' after starting a newGame with O and P ");
  ADD_TEST(testGetPlayer2, "Verify getPlayer2 returns \'P\' after starting a newGame with O and P ");

  ADD_TEST(testPlayMoveSetsSpaceIfAvaliable, 
	   "Verify that PlayMove(0, \'X\') sets space 0 to \'X\' if space 0 is = \' \'");
  ADD_TEST(testPlayMoveReturnsTureIfAvaliable, 
	   "Verify that PlayMove(0, \'X\') returns true if 0 is = \' \'");
  ADD_TEST(testPlayMoveReturnsFalseIfOccupied, 
	   "Verify that PlayMove(0, \'X\') returns false if 0 is occupied");
  ADD_TEST(testValidMoveReturnsTrueWhenSpaceIsAvaliable, 
	   "Verify that validMove() returns True if space 0 is = \' \'");
  ADD_TEST(testValidMoveReturnsFalseWhenSpaceIsOccupied,
	   "Verify that validMove() returns False if space 0 is occupied");
  ADD_TEST(testBoardStateReturnsTieWhenTied,
	   "Verify that getBoardState() returns a enum boardState of TIE when the game is tied");
  ADD_TEST(testBoardStateReturnsWonWhenThereIsAWinner,
	   "Verify that getBoardState() returns a enum boardState of WON when there is a winner");
  ADD_TEST(testBoardStateReturnsPlaying,
	   "Verify that getBoardState() returns a enum boardState of PLAYING when there is not a winner and still spaces available");
  ADD_TEST(testCheckForWinnerReturnsFalse, "Verify that CheckForWinner returns false when there is no winner");
  ADD_TEST(testCheckForWinnerReturnsTrueRow, "Verify that CheckForWinner returns true for 3 in a row");
  ADD_TEST(testCheckForWinnerReturnsTrueCol, "Verify that CheckForWinner returns true for 3 in a col");
  ADD_TEST(testCheckForWinnerReturnsTrueDiagonalUp, "Verify that CheckForWinner returns true for diagonal spaces 0,4,8");
  ADD_TEST(testCheckForWinnerReturnsTrueDiagonalDown, "Verify that CheckForWinner returns true for diagonal spaces 6, 4, 2");
  ADD_TEST(testCheckForWinnerSetsChar, "Verify that CheckForWinner sets char passed in to the winner if there is one");
  ADD_TEST(testGetAvailableSpacesSize9, "Verify getAvailableSpaces returns a vector of size 9 when no moves have been played");
  ADD_TEST(testGetAvailableSpacesSize8, "Verify getAvailableSpaces returns a vector of size 8 when 1 moves have been played");
  ADD_TEST(testGetAvailableSpacesSize0, "Verify getAvailableSpaces returns a vector of size 0 when 9 moves have been played");
  return Tests;
}

void TestGameBoardTTT::testCopyConstructor() {
  GameBoardTTT board1;
  board1.playMove(0, 'X');
  GameBoardTTT board2 = board1;
  board1.clear(' ');
  CPPUNIT_ASSERT_EQUAL('X', board2.getSpace(0));
}

void TestGameBoardTTT::testAssignmentOperator() {
  GameBoardTTT board1;
  GameBoardTTT board2;
  board1.clear('A');
  board2.clear('B');
  board1 = board2;
  board2.clear('C');
  CPPUNIT_ASSERT_EQUAL('B', board1.getSpace(0));
}

void TestGameBoardTTT::testGetPlayer1() {
  GameBoardTTT board1;
  board1.newGame('O', 'P');
  CPPUNIT_ASSERT_EQUAL('O', board1.getPlayer1());
}

void TestGameBoardTTT::testGetPlayer2() {
  GameBoardTTT board1;
  board1.newGame('O', 'P');
  CPPUNIT_ASSERT_EQUAL('P', board1.getPlayer2());
}

void TestGameBoardTTT::testPlayMoveSetsSpaceIfAvaliable() {
  testBoardTTT->playMove(0, 'X');
  CPPUNIT_ASSERT_EQUAL('X', testBoardTTT->getSpace(0));
}

void TestGameBoardTTT::testPlayMoveReturnsTureIfAvaliable() {
  CPPUNIT_ASSERT(testBoardTTT->playMove(0, 'X'));
}

void TestGameBoardTTT::testPlayMoveReturnsFalseIfOccupied() {
  testBoardTTT->playMove(0, 'O');
  CPPUNIT_ASSERT_EQUAL(false, testBoardTTT->playMove(0, 'X'));
}  
  
void TestGameBoardTTT::testValidMoveReturnsTrueWhenSpaceIsAvaliable() {
  CPPUNIT_ASSERT(testBoardTTT->validMove(0));
}
void TestGameBoardTTT::testValidMoveReturnsFalseWhenSpaceIsOccupied() {
  testBoardTTT->playMove(0, 'X');
  CPPUNIT_ASSERT_EQUAL(false, testBoardTTT->validMove(0));
}

void TestGameBoardTTT::testBoardStateReturnsTieWhenTied() {
  GameBoardTTT::boardState stateTied = GameBoardTTT::TIED;
  testBoardTTT->playMove(0, 'T');
  testBoardTTT->playMove(1, 'X');
  testBoardTTT->playMove(2, 'T');
  testBoardTTT->playMove(3, 'X');
  testBoardTTT->playMove(4, 'T');
  testBoardTTT->playMove(5, 'X');
  testBoardTTT->playMove(6, 'X');
  testBoardTTT->playMove(7, 'T');
  testBoardTTT->playMove(8, 'X');
  CPPUNIT_ASSERT_EQUAL(stateTied, testBoardTTT->getBoardState());
}

void TestGameBoardTTT::testBoardStateReturnsWonWhenThereIsAWinner() {
  GameBoardTTT::boardState stateTied = GameBoardTTT::WON;
  testBoardTTT->playMove(0, 'T');
  testBoardTTT->playMove(1, 'T');
  testBoardTTT->playMove(2, 'T');
  CPPUNIT_ASSERT_EQUAL(stateTied, testBoardTTT->getBoardState());
}

void TestGameBoardTTT::testBoardStateReturnsPlaying() {
  GameBoardTTT::boardState stateTied = GameBoardTTT::PLAYING;
  testBoardTTT->playMove(0, 'T');
  testBoardTTT->playMove(1, 'X');
  testBoardTTT->playMove(2, 'T');
  CPPUNIT_ASSERT_EQUAL(stateTied, testBoardTTT->getBoardState());
}

void TestGameBoardTTT::testCheckForWinnerReturnsFalse() {
  CPPUNIT_ASSERT_EQUAL(false, testBoardTTT->checkForWinner());
}

void TestGameBoardTTT::testCheckForWinnerReturnsTrueRow() {
  testBoardTTT->playMove(0, 'X');
  testBoardTTT->playMove(1, 'X');
  testBoardTTT->playMove(2, 'X');
  CPPUNIT_ASSERT(testBoardTTT->checkForWinner());
}

void TestGameBoardTTT::testCheckForWinnerReturnsTrueCol() {
  testBoardTTT->playMove(1, 'X');
  testBoardTTT->playMove(4, 'X');
  testBoardTTT->playMove(7, 'X');
  CPPUNIT_ASSERT(testBoardTTT->checkForWinner());
}

void TestGameBoardTTT::testCheckForWinnerReturnsTrueDiagonalUp() {
  testBoardTTT->playMove(0, 'X');
  testBoardTTT->playMove(4, 'X');
  testBoardTTT->playMove(8, 'X');
  CPPUNIT_ASSERT(testBoardTTT->checkForWinner());
}

void TestGameBoardTTT::testCheckForWinnerReturnsTrueDiagonalDown() {
  testBoardTTT->playMove(6, 'X');
  testBoardTTT->playMove(4, 'X');
  testBoardTTT->playMove(2, 'X');
  CPPUNIT_ASSERT(testBoardTTT->checkForWinner());
}

void TestGameBoardTTT::testCheckForWinnerSetsChar() {
  testBoardTTT->playMove(0, 'X');
  testBoardTTT->playMove(1, 'X');
  testBoardTTT->playMove(2, 'X');
  char temp_ = ' ';
  testBoardTTT->checkForWinner(temp_);
  CPPUNIT_ASSERT_EQUAL('X', temp_);
}

void TestGameBoardTTT::testGetAvailableSpacesSize9() {
  
  CPPUNIT_ASSERT_EQUAL(9, (int)testBoardTTT->getAvailableSpaces().size());
}
void TestGameBoardTTT::testGetAvailableSpacesSize8() {
  testBoardTTT->playMove(0, 'X');
  CPPUNIT_ASSERT_EQUAL(8, (int)testBoardTTT->getAvailableSpaces().size());
}
void TestGameBoardTTT::testGetAvailableSpacesSize0() {
  for(int i = 0; i < 9; ++i)
    testBoardTTT->playMove(i, 'X');
  CPPUNIT_ASSERT_EQUAL(0, (int)testBoardTTT->getAvailableSpaces().size());
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestGameBoardTTT::suite());
  runner.run();
  return 0;
}

