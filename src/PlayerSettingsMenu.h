// Tyler Decker
// PlayerSettingsMenu.h

#ifndef _PLAYERSETTINGSMENU_H
#define _PLAYERSETTINGSMENU_H

#include<string>
#include<vector>
#include "GameIoTicTacToe.h"
#include "GameBoardTTT.h"
#include "TicTacToePlayer.h"
#include "GameMenu.h"

class PlayerSettingsMenu {
 private:
  GameIoTicTacToe * myIo;
  TicTacToePlayer * p1;
  TicTacToePlayer * p2;
  GameBoardTTT * myBoard;
  GameMenu mainMenu;
  GameMenu changePlayer;
  char getMark();
  
 public:
  PlayerSettingsMenu(GameIoTicTacToe * gameIo, GameBoardTTT * board, TicTacToePlayer * p1, TicTacToePlayer * p2);
  void run();
  void configure(TicTacToePlayer * player);
};
#endif
