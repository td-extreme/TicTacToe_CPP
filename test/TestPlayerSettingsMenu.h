// TestPlayerSettingsMenu.h
// Tyler Decker

#ifndef _TESTPLAYERSETTINGSMENU_H
#define _TESTPLAYERSETTINGSMENU_H

#include <iostream>
#include <streambuf>
#include <sstream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include "GameIoTicTacToe.h"
#include "GameBoardTTT.h"
#include "TicTacToePlayer.h"
#include "PlayerSettingsMenu.h"

class TestPlayerSettingsMenu : public CppUnit::TestCase {
 private:
  std::stringstream buffer;
  std::stringstream myin;
  std::streambuf * sbuf;
  GameIoTicTacToe * myIo;
  TicTacToePlayer * p1;
  TicTacToePlayer * p2;
  GameBoardTTT * myBoard;
  PlayerSettingsMenu * testMenu;  
   
 public:  
  TestPlayerSettingsMenu() {}
  TestPlayerSettingsMenu(std::string name) : CppUnit::TestCase(name) {}
  void testConfigurePlayerHuman();
  void testConfigurePlayerPcEasy();
  void testConfigurePlayerPcMedium();
  void testConfigurePlayerPcHard();
  void testConfigurePlayerMark();
  void setUp();
  void tearDown();
  static CppUnit::Test *suite();
};
#endif
