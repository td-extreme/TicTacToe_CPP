// TestMoveLog.h
// Tyler Decker

#ifndef _TestMoveLog_H
#define _TestMoveLog_H

#include <iostream>
#include <streambuf>
#include <sstream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "MoveLog.h"

class TestMoveLog : public CppUnit::TestCase {
  
 public:  
  TestMoveLog() {}
  TestMoveLog(std::string name) : CppUnit::TestCase(name) {}
  void setUp();
  void tearDown();
  void testClear();
  void testAdd();
  static CppUnit::Test *suite();
};
#endif
