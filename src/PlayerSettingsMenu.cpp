// Tyler Decker
// PlayerSettingsMenu.cpp

#include "PlayerSettingsMenu.h"

PlayerSettingsMenu::PlayerSettingsMenu(GameIoTicTacToe * gameIo, GameBoardTTT * board, TicTacToePlayer * p1, TicTacToePlayer * p2)
  : myIo(gameIo), myBoard(board), p1(p1), p2(p2), mainMenu("Player Settings Menu"), changePlayer("Configure Player")  {
  mainMenu.add("Change Player 1 properties");
  mainMenu.add("Change Player 2 properties");
  mainMenu.add("Play with these Settings");

  changePlayer.add("Human");
  changePlayer.add("Easy Computer");
  changePlayer.add("Medium Computer");
  changePlayer.add("Hard Computer");
}

void PlayerSettingsMenu::run() {
  char input_;
  do {
    myIo->clearScreen();
    myIo->printPlayerInfo(p1->getMark(), p1->getType(), p2->getMark(), p2->getType());
    myIo->print(mainMenu);
    input_ = myIo->getInput(mainMenu.choices());
    switch(input_) {
    case '1':
      configure(p1);
      break;
    case '2':
      configure(p2);
      break;
    }
  } while(input_ != '3');
}

char PlayerSettingsMenu::getMark() {
  std::vector<char> choices_;
  for(int i = 'a'; i < 'z'; ++i)
    choices_.push_back(i);
  for(int i = 'A'; i < 'Z'; ++i)
    choices_.push_back(i);
  myIo->print("Select a letter for this player: ");
  return myIo->getInput(choices_);

}

void PlayerSettingsMenu::configure(TicTacToePlayer * player) {
  char input_;
  char mark_;
  
  myIo->print(changePlayer);
  input_ = myIo->getInput(changePlayer.choices());

  do {
    mark_ = getMark();
    delete player;
    switch (input_) {
    case '1':
      player = new TicTacToePlayerHuman(mark_, myBoard, myIo);
      break;
    case '2':
      player = new TicTacToePlayerPcEasy(mark_, myBoard, myIo);
      break;
    case '3':
      player = new TicTacToePlayerPcMedium(mark_, myBoard, myIo);
      break;
    case '4':
      player = new TicTacToePlayerPcHard(mark_, myBoard, myIo);
      break;
    }
    myIo->print("**The Other Player is using this mark, please select a different letter.\n");
  } while (p1->getMark() == p2->getMark());
}
