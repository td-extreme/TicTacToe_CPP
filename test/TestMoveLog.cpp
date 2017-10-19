// TestMoveLog.cpp
// Tyler Decker

#include "TestMoveLog.h"
#include <iostream>

// This Macro is used to add a test to the test suite
#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestMoveLog> \
   (testDescription, &TestMoveLog::testName))	  \

void TestMoveLog::setUp() {}
void TestMoveLog::tearDown() {}

CppUnit::Test *TestMoveLog::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestMoveLogCase");
  ADD_TEST(testAdd, "Ensure that add works properly");
  ADD_TEST(testClear, "Ensure getLog() returns an empty vector after clear()");
  return Tests;
}

void TestMoveLog::testClear() {
  MoveLog myLog_;
  myLog_.add(3, 'X');
  myLog_.clear();
  int size_ = myLog_.getLog().size();
  CPPUNIT_ASSERT_EQUAL(0, size_);
}

void TestMoveLog::testAdd() {
  MoveLog myLog_;
  std::vector<std::string> testV_;
  std::string testString_ = " - Player X played square # 3";
  myLog_.add(3, 'X');
  testV_ = myLog_.getLog();
  CPPUNIT_ASSERT_EQUAL(testString_, testV_[0]);
}

int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestMoveLog::suite());
  runner.run();
  return 0;
}
