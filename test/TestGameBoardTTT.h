// TestGameBoardTTT.h
// Tyler Decker

#ifndef _TESTGameBoardTTT_H
#define _TESTGameBoardTTT_H

#include <iostream>
#include <string>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "GameBoardTTT.h"

class TestGameBoardTTT : public CppUnit::TestCase {

 private:
  GameBoardTTT * testBoardTTT;

 public:
  TestGameBoardTTT() {}
  TestGameBoardTTT(std::string name) : CppUnit::TestCase(name) {}
  void setUp();
  void tearDown();
  void testCopyConstructor();
  void testAssignmentOperator();
  void testGetPlayer1();
  void testGetPlayer2();
  void testPlayMoveSetsSpaceIfAvaliable();
  void testPlayMoveReturnsTureIfAvaliable();
  void testPlayMoveReturnsFalseIfOccupied();
  void testValidMoveReturnsTrueWhenSpaceIsAvaliable();
  void testValidMoveReturnsFalseWhenSpaceIsOccupied();
  void testBoardStateReturnsTieWhenTied();
  void testBoardStateReturnsWonWhenThereIsAWinner();
  void testBoardStateReturnsPlaying();
  void testCheckForWinnerReturnsFalse();
  void testCheckForWinnerReturnsTrueRow();
  void testCheckForWinnerReturnsTrueCol();
  void testCheckForWinnerReturnsTrueDiagonalUp();
  void testCheckForWinnerReturnsTrueDiagonalDown();    
  void testCheckForWinnerSetsChar();
  void testGetAvailableSpacesSize9();
  void testGetAvailableSpacesSize8();
  void testGetAvailableSpacesSize0();
  static CppUnit::Test *suite();
};
#endif
