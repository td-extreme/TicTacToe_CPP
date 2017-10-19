// TestGameMenu.cpp
// Tyler Decker

#include "TestGameMenu.h"
#include <iostream>

// This Macro is used to add a test to the test suite
#define ADD_TEST(testName, testDescription) Tests->addTest	\
  (new CppUnit::TestCaller<TestGameMenu>			\
   (testDescription, &TestGameMenu::testName))			\

void TestGameMenu::setUp() {}
void TestGameMenu::tearDown() {}
  
CppUnit::Test *TestGameMenu::suite () {
  CppUnit::TestSuite *Tests =
    new CppUnit::TestSuite("TestGameMenuCase");
  ADD_TEST(testGetTitle, "Make sure get Title returns \"Test\" when that was passed in to the constructor of object");
  ADD_TEST(testAdd, "Make sure that the size of the menu Vector is 1 after 1 item is added");
  ADD_TEST(testGetChoices, "Make sure that choices returns a vector where index 2 = 3 when there are at least 3 members.");
  return Tests;
}

void TestGameMenu::testGetTitle() {
  std::string test_ = "Test";
  GameMenu testMenu(test_);
  CPPUNIT_ASSERT_EQUAL(test_, testMenu.getTitle());
}
void TestGameMenu::testAdd() {
  GameMenu testMenu("Test");
  testMenu.add("item");
  int test2_ = testMenu.size();
  CPPUNIT_ASSERT_EQUAL(1, test2_);
}
  
void TestGameMenu::testGetChoices() {
  GameMenu test_("test");
  std::vector<int> testVector_;
  for (int i = 0; i < 3; ++i) {
    test_.add("item");
    testVector_.push_back(i);
  }
  CPPUNIT_ASSERT_EQUAL('3', test_.choices()[2]);      
}
int main (int argc, char* argv[]) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestGameMenu::suite());
  runner.run();
  return 0;
}
