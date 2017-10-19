// TestTicTacToePlayer.h
// Tyler Decker


#ifndef _TESTTICTACTOEPLAYER_H
#define _TESTTICTACTOEPLAYER_H

#include <iostream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <algorithm>

#include "TicTacToePlayer.h"
#include "GameIoTicTacToe.h"
#include "GameBoardTTT.h"

class TestTicTacToePlayer : public CppUnit::TestCase {
 private:
  GameBoardTTT myBoard;
  GameIoTicTacToe * myIo;
  TicTacToePlayer * myHuman;
  TicTacToePlayer * myPcEasy;
  TicTacToePlayer * myPcMedium;
  TicTacToePlayer * myPcHard;

 public:
  TestTicTacToePlayer() {}
  TestTicTacToePlayer(std::string name) : CppUnit::TestCase(name) {}
  void setUp();
  void tearDown();

  void testReturnGetTypeHuman();
  void testReturnGetTypePcEasy();
  void testReturnGetTypePcMedium();
  void testReturnGetTypePcHard();

  void testGetMark();

  void testGetRandomMoveBlankBoard();
  void testGetRandomMoveCenterClosed();
  void testGetRandomMoveOneSpaceLeft();
  void testGetRandomMoveFullBoard();

  void testGetCornerMoveBlankBoard();
  void testGetCornerMoveTopLeftClosed();
  void testGetCornerMoveOneSpaceLeft();
  void testGetCornerMoveFullBoard();

  void testGetBestMoveEmptyBoard();
  void testGetBestMoveFullBoard();

  void testWillMoveWinRow();
  void testWillMoveWinCol();
  void testWillMoveWinDiagonal();
  void testWillMoveWinFalse();

  void testGetOpponentMark();
  
  
  
  static CppUnit::Test *suite();
};
#endif
