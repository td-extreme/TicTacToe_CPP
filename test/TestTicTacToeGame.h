// TestTicTacToeGame.h
// Tyler Decker

#ifndef _TESTTICTACTOEGAME_H
#define _TESTTICTACTOEGAME_H

#include <iostream>
#include <streambuf>
#include <sstream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "GameBoard2D.h"
#include "GameBoardTTT.h"
#include "TicTacToePlayer.h"
#include "GameIoTicTacToe.h"
#include "TicTacToeGame.h"
#include "MoveLog.h"

class TestTicTacToeGame : public CppUnit::TestCase {
 private:
  std::stringstream buffer;
  std::stringstream myin;
  std::streambuf * sbuf;
  TicTacToeGame * myGame;
  GameBoardTTT * myBoard;
  GameIoTicTacToe * myIo;
  TicTacToePlayer * p1;
  TicTacToePlayer * p2;
   
 public:  
  TestTicTacToeGame() {}
  TestTicTacToeGame(std::string name) : CppUnit::TestCase(name) {}
  void testSetFirstPlayer1();
  void testSetFirstPlayer2();
  void testSwitchTurns();
  void testPlayAgainYes();
  void testPlayAgainNo();
  void setUp();
  void tearDown();
  static CppUnit::Test *suite();
};
#endif
