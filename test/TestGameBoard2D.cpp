// TestGameBoard2D.cpp
// Tyler Decker

#include "TestGameBoard2D.h"
#include <iostream>

// This Macro is used to add a test to the test suite
#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestGameBoard2D> \
   (testDescription, &TestGameBoard2D::testName))	  \

void TestGameBoard2D::setUp() {
  testBoardChar = new GameBoard2D<char>(3, 3);
  testBoardInt = new GameBoard2D<int>(3, 3);
  testBoardInt3x2 = new GameBoard2D<int>(3, 2);
}

void TestGameBoard2D::tearDown() {
  delete testBoardChar;
  delete testBoardInt;
  delete testBoardInt3x2;
}

CppUnit::Test *TestGameBoard2D::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestGameBoard2DCase");

  ADD_TEST(testDeepCopyForCopyConstructor, "Ensure that the copy consturctor make a deep copy");
    
  ADD_TEST(testDeepCopyForAssignmentOperator, "Ensure that the assignment operator make a deep copy");

  ADD_TEST(testGetColSize, "Assert that for a 3x3 GameBoard2D .colSize() returns 3");
  ADD_TEST(testGetRowSize, "Assert that for a 3x3 GameBoard2D .rowSize() returns 3");
  ADD_TEST(testGetBoardSize, "Assert that for a 3x3 GameBoard2D .Size() returns 9");
  
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(0) returns 0");
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(2) returns 1");
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(5) returns 2");    
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(0) returns 0");
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(3) returns 1");
  ADD_TEST(testToRow0, "On a 3x2 board ensure that .toRow(5) returns 1");    
  
  ADD_TEST(testClearBoardCharSpace0, 
    "After performing .Clear(\'T\') on a 3x3 GameBoard2D<char> ; getSpace(0) returns \'T\'");
  ADD_TEST(testClearBoardCharSpace1, 
    "After performing .Clear(\'T\') on a 3x3 GameBoard2D<char> ; getSpace(1) returns \'T\'");
  ADD_TEST(testClearBoardCharSpace2, 
    "After performing .Clear(\'T\') on a 3x3 GameBoard2D<char> ; getSpace(2) returns \'T\'");
  ADD_TEST(testClearBoardCharSpace8, 
    "After performing .Clear(\'T\') on a 3x3 GameBoard2D<char> ; getSpace(8) returns \'T\'");

  ADD_TEST(testClearBoardIntSpace0, 
    "After performing .Clear(1) on a 3x3 GameBoard2D<int> ; getSpace(0) returns 1");
  ADD_TEST(testClearBoardIntSpace5, 
    "After performing .Clear(1) on a 3x3 GameBoard2D<int> ; getSpace(5) returns 1");
  ADD_TEST(testClearBoardIntSpace8, 
    "After performing .Clear(1) on a 3x3 GameBoard2D<int> ; getSpace(8) returns 1");
    
  ADD_TEST(testSetAndGetRow1Col1, 
    "Ensure that after .setSpace(1, 1, \'X\') ; .getSpace(1, 1) returns \'X\'");
  ADD_TEST(testSetAndGetRow2Col2, 
    "Ensure that after .setSpace(2, 2, \'X\') ; .getSpace(2, 2) returns \'X\'");
    
  ADD_TEST(testSetAndGetSpace5,
    "Ensure that after .setSpace(5, \'X\') ; .getSpace(5) returns \'X\'");
  
  ADD_TEST(testSwapBySpaceArgument1,
    "Ensure that after .swap(1, 2) the first argument has been changed to the value of the second");
  ADD_TEST(testSwapBySpaceArgument2,
    "Ensure that after .swap(1, 2) the second argument has been changed to the value of the first");
  ADD_TEST(testSwapByRowColArgument1,
    "Ensure that after .swap(1, 2, 0, 0) the value for getSpace(1, 2) returns the value that was perviously in board[0, 0]");
  ADD_TEST(testSwapByRowColArgument2,
    "Ensure that after .swap(1, 2, 0, 0) the value for getSpace(0, 0) returns the value that was perviously in board[1, 2]");

  ADD_TEST(testToString2x2, "Ensure that a toString() returns a string of a 2x2 board");

  return Tests;
}

void TestGameBoard2D::testDeepCopyForCopyConstructor() {
  GameBoard2D<char> board1(2,2);
  board1.clear('T');
  GameBoard2D<char> board2 = board1;
  board1.clear('X');
  CPPUNIT_ASSERT_EQUAL('T', board2.getSpace(0));  
}

void TestGameBoard2D::testDeepCopyForAssignmentOperator() {
  GameBoard2D<char> board1(1,1);
  GameBoard2D<char> board2(1,1);
  board1.clear('A');
  board2.clear('B');
  board1 = board2;
  board2.setSpace(0, 'C');
  CPPUNIT_ASSERT_EQUAL('B', board1.getSpace(0));
}

void TestGameBoard2D::testGetColSize() {
  CPPUNIT_ASSERT_EQUAL(3, testBoardChar->colSize());
}

void TestGameBoard2D::testGetRowSize() {
  CPPUNIT_ASSERT_EQUAL(3, testBoardChar->rowSize());
}

void TestGameBoard2D::testGetBoardSize() {
  CPPUNIT_ASSERT_EQUAL(9, testBoardChar->size());
}

void TestGameBoard2D::testToRow0() {
  CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toRow(0));
}
void TestGameBoard2D::testToRow2() {
   CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toRow(2));
}
void TestGameBoard2D::testToRow5() {
   CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toRow(5));
}

void TestGameBoard2D::testToCol0() {
  CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toCol(0));
}

void TestGameBoard2D::testToCol3() {
  CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toCol(3));
}
void TestGameBoard2D::testToCol5() {
  CPPUNIT_ASSERT_EQUAL(0, testBoardInt3x2->toCol(5));
}
void TestGameBoard2D::testClearBoardCharSpace0() {
  testBoardChar->clear('T');
  CPPUNIT_ASSERT_EQUAL('T', testBoardChar->getSpace(0));
}

void TestGameBoard2D::testClearBoardCharSpace1() {
  testBoardChar->clear('T');
  CPPUNIT_ASSERT_EQUAL('T', testBoardChar->getSpace(1));
}

void TestGameBoard2D::testClearBoardCharSpace2() {
  testBoardChar->clear('T');
  CPPUNIT_ASSERT_EQUAL('T', testBoardChar->getSpace(2));
}

void TestGameBoard2D::testClearBoardCharSpace8() {
  testBoardChar->clear('T');
  CPPUNIT_ASSERT_EQUAL('T', testBoardChar->getSpace(8));
}

void TestGameBoard2D::testClearBoardIntSpace0() {
  testBoardInt->clear(1);
  CPPUNIT_ASSERT_EQUAL(1, testBoardInt->getSpace(0));
}

void TestGameBoard2D::testClearBoardIntSpace5() {
  testBoardInt->clear(1);
  CPPUNIT_ASSERT_EQUAL(1, testBoardInt->getSpace(5));
}

void TestGameBoard2D::testClearBoardIntSpace8() {
  testBoardInt->clear(1);
  CPPUNIT_ASSERT_EQUAL(1, testBoardInt->getSpace(8));
}

void TestGameBoard2D::testSetAndGetRow1Col1() {
  testBoardChar->setSpace(1, 1, 'X');
  CPPUNIT_ASSERT_EQUAL('X', testBoardChar->getSpace(1, 1));
}

void TestGameBoard2D::testSetAndGetRow2Col2() {
  testBoardChar->setSpace(2, 2, 'X');
  CPPUNIT_ASSERT_EQUAL('X', testBoardChar->getSpace(2, 2));
}

void TestGameBoard2D::testSetAndGetSpace5() {
  testBoardChar->setSpace(5, 'X');
  CPPUNIT_ASSERT_EQUAL('X', testBoardChar->getSpace(5));

}

void TestGameBoard2D::testSwapBySpaceArgument1() {
  testBoardChar->setSpace(1, 'X');
  testBoardChar->setSpace(2, 'O');
  testBoardChar->swap(1, 2);
  CPPUNIT_ASSERT_EQUAL('O', testBoardChar->getSpace(1));
}

void TestGameBoard2D::testSwapBySpaceArgument2() {
  testBoardChar->setSpace(1, 'X');
  testBoardChar->setSpace(2, 'O');
  testBoardChar->swap(1, 2);
  CPPUNIT_ASSERT_EQUAL('X', testBoardChar->getSpace(2));
}

void TestGameBoard2D::testSwapByRowColArgument1() {
  testBoardChar->setSpace(1, 2, 'X');
  testBoardChar->setSpace(0, 0, 'O');   
  testBoardChar->swap(1, 2, 0, 0);
  CPPUNIT_ASSERT_EQUAL('O', testBoardChar->getSpace(1, 2));
}
  
void TestGameBoard2D::testSwapByRowColArgument2() {
  testBoardChar->setSpace(1, 2, 'X');
  testBoardChar->setSpace(0, 0, 'O');   
  testBoardChar->swap(1, 2, 0, 0);
  CPPUNIT_ASSERT_EQUAL('X', testBoardChar->getSpace(0, 0));
}

void TestGameBoard2D::testToString2x2() {
  delete testBoardChar;
  testBoardChar = new GameBoard2D<char>(2, 2);
  testBoardChar->clear('T');
  std::string temp_ = testBoardChar->toString();
  std::string expected_ = "\n --- --- \n| T | T |\n --- --- \n| T | T |\n --- --- ";
  CPPUNIT_ASSERT_EQUAL(expected_, temp_);

}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestGameBoard2D::suite());
  runner.run();
  return 0;
}
