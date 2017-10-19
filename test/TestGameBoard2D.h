// TestGameBoard2D.h
// Tyler Decker
// Feb 2nd 2016

#ifndef _TESTGameBoard2D_H
#define _TESTGameBoard2D_H

#include <iostream>
#include <streambuf>
#include <sstream>
#include <string>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "GameBoard2D.h"

class TestGameBoard2D : public CppUnit::TestCase {

 private:
  std::stringstream osBuffer;
  std::streambuf *osbuf;
  GameBoard2D<char> * testBoardChar;
  GameBoard2D<int> * testBoardInt;
  GameBoard2D<int> * testBoardInt3x2;
 
 public:  
  TestGameBoard2D() {}
  TestGameBoard2D(std::string name) : CppUnit::TestCase(name) {}
  void setUp();
  void tearDown();
  void testDeepCopyForCopyConstructor();
  void testDeepCopyForAssignmentOperator();
  void testGetColSize();
  void testGetRowSize();
  void testGetBoardSize();
  void testToRow0();
  void testToRow2();
  void testToRow5();
  void testToCol0();
  void testToCol3();
  void testToCol5();
  void testClearBoardCharSpace0();
  void testClearBoardCharSpace1();
  void testClearBoardCharSpace2(); 
  void testClearBoardCharSpace8();
  void testClearBoardIntSpace0();
  void testClearBoardIntSpace5();
  void testClearBoardIntSpace8();
  void testSetAndGetRow1Col1();
  void testSetAndGetRow2Col2();
  void testSetAndGetSpace5();
  void testSwapBySpaceArgument1();
  void testSwapBySpaceArgument2();
  void testSwapByRowColArgument1();
  void testSwapByRowColArgument2();
  void testToString2x2();
  static CppUnit::Test *suite();
};
#endif
