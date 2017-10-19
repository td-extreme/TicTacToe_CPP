// TestGameMenu.h
// Tyler Decker


#ifndef _TESTGAMEMENU_H
#define _TESTGAMEMENU_H

#include <string>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "GameMenu.h"

class TestGameMenu : public CppUnit::TestCase {
 private:
 
 public:  
  TestGameMenu() {}
  TestGameMenu(std::string name) : CppUnit::TestCase(name) {}
  void testGetTitle();
  void testAdd();
  void testGetChoices();
  void setUp();
  void tearDown();
  static CppUnit::Test *suite();
};
#endif
