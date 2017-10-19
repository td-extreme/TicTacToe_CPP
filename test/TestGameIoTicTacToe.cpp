// TestGameIoTicTacToe.cpp
// Tyler Decker

#include "TestGameIoTicTacToe.h"

#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestGameIoTicTacToe> \
   (testDescription, &TestGameIoTicTacToe::testName))	  \

void TestGameIoTicTacToe::setUp() { 
  sbuf = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  std::cin.clear();
  std::cin.rdbuf(myin.rdbuf());
  testBoardTTT = new GameBoardTTT();
  testIo = new GameIoTicTacToeText();
}
void TestGameIoTicTacToe::tearDown() {
  std::cout.rdbuf(sbuf);
  delete testBoardTTT;
  delete testIo;
}

CppUnit::Test *TestGameIoTicTacToe::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestGameIoTicTacToeCase");
  
  ADD_TEST(testPrintString, "Ensure that cout of printString() equals the string passed in");
  ADD_TEST(testPrintInt, "Ensure cout buffer equals \"5\" when print(5) is called.");
  ADD_TEST(testGetYesNoTrue, "Ensure that getYesNo() returns ture when user enters y ");
  ADD_TEST(testGetYesNoFalse, "Ensure that getYesNo() returns false when user enters n ");
  ADD_TEST(testPrintGameBoardTTT, "Ensure that print(gameBoardTTT) prints correctly");
  ADD_TEST(testPrintGameBoard2D, "Ensure that print(GameBoard2D) prints legend correctly");
  ADD_TEST(testPrintMoveLog, "Ensure that print(MoveLog log) prints moveLog correctly");
  ADD_TEST(testPrintGameMenu, "Ensure that print(GameMenu myMenu) prints correctly");
  ADD_TEST(testPrintPlayerInfo, "Ensure that printPlayerInfo() prints correctly");
  ADD_TEST(testGetInput, "Ensure that getInput(std::vector<char> choices_) returns '6' after user trys inputs 3, 5, 6 when 3 and 5 are not in vector and 6 is");
  return Tests;
}

void TestGameIoTicTacToe::testPrintString() {
  std::string test_ = "Test String";
  testIo->print(test_);
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_); 
}

void TestGameIoTicTacToe::testPrintInt() {
  testIo->print(5);
  std::string test_ = "5";
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testPrintGameBoardTTT() {
  GameBoardTTT testBoard_;
  testBoard_.clear('T');
  std::string test_ = "\n\n Tic Tac Toe";
  test_.append(testBoard_.toString());
  testIo->print(testBoard_);
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testPrintGameBoard2D() {
  GameBoard2D<char> testBoard_(3, 3);
  testBoard_.clear('T');
  testIo->print(testBoard_);
  std::string test_ = "\n\n     KEY";
  test_.append(testBoard_.toString());
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testGetYesNoTrue() {
  myin << "y\n";
  CPPUNIT_ASSERT(testIo->getYesNo());
}

void TestGameIoTicTacToe::testGetYesNoFalse() {
  myin << "n\n";
  CPPUNIT_ASSERT_EQUAL(false, testIo->getYesNo());
}

void TestGameIoTicTacToe::testPrintMoveLog() {
  MoveLog testLog;
  testLog.add(3, 'X');
  testIo->print(testLog);
  std::string test_ = "\nMove (1) - Player X played square # 3\n";
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testPrintGameMenu() {
  GameMenu testMenu("Title");
  testMenu.add("item 1");
  std::string test_ = "\nTitle\n  1 item 1\nSelect an option (or type quit to exit): ";
  testIo->print(testMenu);
  std::string test2_ = buffer.str();
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testPrintPlayerInfo() {
  testIo->printPlayerInfo('X', "Human", 'O', "PC Easy");
  std::string test2_ = buffer.str();
  std::string test_ = "\n --------------      --------------";
  test_.append("\n |  Player 1  |      |  Player 2  |\n |------------|  VS  |------------|");
  test_.append("\n | Human      |      | PC Easy    |\n | mark : X   |      | mark : O   |");
  test_.append("\n --------------      --------------");
  CPPUNIT_ASSERT_EQUAL(test_, test2_);
}

void TestGameIoTicTacToe::testGetInput() {
  myin << "3\n5\n6\n";
  std::vector<char> choices_;
  choices_.push_back('6');
  char test2_ = testIo->getInput(choices_);
  CPPUNIT_ASSERT_EQUAL('6', test2_);
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestGameIoTicTacToe::suite());
  runner.run();
  return 0;
}
