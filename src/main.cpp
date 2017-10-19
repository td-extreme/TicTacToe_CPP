// Tyler Decker
// main.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <unistd.h>

#include "GameIoTicTacToe.h"
#include "GameBoardTTT.h"
#include "TicTacToePlayer.h"
#include "TicTacToeGame.h"
#include "PlayerSettingsMenu.h"

int main() {
  
  GameIoTicTacToeText gameIo;
  GameBoardTTT myBoard;
  TicTacToePlayer * p1 = new TicTacToePlayerPcHard('X', &myBoard, &gameIo);
  TicTacToePlayer * p2 = new TicTacToePlayerHuman('O', &myBoard, &gameIo);

  PlayerSettingsMenu mySettings(&gameIo, &myBoard, p1, p2);
  TicTacToeGame myGame(&gameIo, &myBoard, p1, p2);

  while (true) {
    mySettings.run();
    myGame.gameLoop();
  }
}

