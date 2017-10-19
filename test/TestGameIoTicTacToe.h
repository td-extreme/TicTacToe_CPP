// TestGameIoTicTacToe.h
// Tyler Decker

#ifndef _TestGameIoTicTacToe_H
#define _TestGameIoTicTacToe_H

#include <iostream>
#include <string>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "GameIoTicTacToe.h"
#include "GameBoardTTT.h"
#include "GameBoard2D.h"
#include "TicTacToePlayer.h"
#include "MoveLog.h"
#include "GameMenu.h"

class TestGameIoTicTacToe : public CppUnit::TestCase {

 private:
  std::stringstream buffer;
  std::stringstream myin;
  std::streambuf * sbuf;
  GameBoardTTT * testBoardTTT;
  GameIoTicTacToe * testIo;

 public:
  TestGameIoTicTacToe() {}
  TestGameIoTicTacToe(std::string name) : CppUnit::TestCase(name) {}
  void setUp();
  void tearDown();
  void testPrintString();
  void testPrintInt();
  void testPrintGameBoardTTT();
  void testPrintGameBoard2D();
  void testPrintMoveLog();
  void testPrintGameMenu();  
  void testGetYesNoTrue();
  void testGetYesNoFalse();
  void testPrintPlayerInfo();
  void testGetInput();
  static CppUnit::Test *suite();
};
#endif
