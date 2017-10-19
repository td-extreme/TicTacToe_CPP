// TestPlayerSettingsMenu.cpp
// Tyler Decker

#include "TestPlayerSettingsMenu.h"
#include <iostream>

// This Macro is used to add a test to the test suite
#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestPlayerSettingsMenu> \
   (testDescription, &TestPlayerSettingsMenu::testName))	  \

void TestPlayerSettingsMenu::setUp() {
  myBoard = new GameBoardTTT();
  myIo = new GameIoTicTacToeText();
  p1 = new TicTacToePlayerHuman('1', myBoard, myIo);
  p2 = new TicTacToePlayerHuman('1', myBoard, myIo);
  testMenu = new PlayerSettingsMenu(myIo, myBoard, p1, p2);
  
  sbuf = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  
  std::cin.clear();
  myin << " ";
  std::cin.rdbuf(myin.rdbuf());
}

void TestPlayerSettingsMenu::tearDown() {
  delete myBoard;
  delete myIo;
  delete p1;
  delete p2;
  delete testMenu;
  std::cout.rdbuf(sbuf);
}

CppUnit::Test *TestPlayerSettingsMenu::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestPlayerSettingsMenuCase");
  ADD_TEST(testConfigurePlayerHuman, "Ensure player is set to human when option 1 is selected");
  ADD_TEST(testConfigurePlayerPcEasy, "Ensure player is set to PcEasy when option 2 is selected");
  ADD_TEST(testConfigurePlayerPcMedium, "Ensure player is set to PcMedium when option 3 is selected");
  ADD_TEST(testConfigurePlayerPcHard, "Ensure player is set to PcHard when option 4 is selected");
  ADD_TEST(testConfigurePlayerMark, "Ensure player mark is 'T' after configure is complete");
  return Tests;
}

void TestPlayerSettingsMenu::testConfigurePlayerHuman() {
  myin << "1\nX\n";
  testMenu->configure(p1);
  std::string type_ = p1->getType();
  std::string test_ = "Human";
  CPPUNIT_ASSERT_EQUAL(test_, type_);
}

void TestPlayerSettingsMenu::testConfigurePlayerPcEasy() {
  myin << "2\nX\n";
  testMenu->configure(p1);
  std::string type_ = p1->getType();
  std::string test_ = "PC Easy";
   CPPUNIT_ASSERT_EQUAL(test_, type_);
}

void TestPlayerSettingsMenu::testConfigurePlayerPcMedium() {
  myin << "3\nX\n";
  testMenu->configure(p1);
  std::string type_ = p1->getType();
  std::string test_ = "PC Medium";
   CPPUNIT_ASSERT_EQUAL(test_, type_);
}

void TestPlayerSettingsMenu::testConfigurePlayerPcHard() {
  myin << "4\nX\n";
  testMenu->configure(p1);
  std::string type_ = p1->getType();
  std::string test_ = "PC Hard";
   CPPUNIT_ASSERT_EQUAL(test_, type_);
}

void TestPlayerSettingsMenu::testConfigurePlayerMark() {
  myin << "1\nT\n";
  testMenu->configure(p1);
  char mark_ = p1->getMark();
  char test_ = 'T';
  CPPUNIT_ASSERT_EQUAL(test_, mark_);
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestPlayerSettingsMenu::suite());
  runner.run();
  return 0;
}
