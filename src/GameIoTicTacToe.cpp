// GameIoTicTacToe.cpp
// Tyler Decker

#include "GameIoTicTacToe.h"

GameIoTicTacToe::GameIoTicTacToe() {
  sbuf = std::cout.rdbuf();
}

void GameIoTicTacToeText::clearScreen() {
  std::cout << std::endl;
  if (sbuf == std::cout.rdbuf())
    system("clear");
}

void GameIoTicTacToeText::print(GameBoardTTT gameBoardTTT) {
  std::cout << "\n\n Tic Tac Toe";
  std::cout << gameBoardTTT.toString();
}

void GameIoTicTacToeText::printGameOver(GameBoardTTT gameBoardTTT) {
  char winner_;
  std::cout << "\n\n\t *** Game  Over ***\n";
  if (gameBoardTTT.getBoardState() == 'T') {
    std::cout << "\t -- Tied Game --\n" << std::endl;
  } else {
    gameBoardTTT.checkForWinner(winner_);
    std::cout << "\t -- Player " << winner_ << " Won --";
  }
}

void GameIoTicTacToeText::print(int outInt){
  std::cout << outInt;
}

void GameIoTicTacToeText::print(std::string outString) {
  std::cout << outString;
}

void GameIoTicTacToeText::print(GameBoard2D<int> gameBoard2D) {
  std::cout << gameBoard2D.toString();
}

void GameIoTicTacToeText::print(GameBoard2D<char> gameBoard2D) {
  std::cout << "\n\n     KEY";
  std::cout << gameBoard2D.toString();
}

void GameIoTicTacToeText::printPlayerInfo(char mark1, std::string type1, char mark2, std::string type2) {
  std::cout << "\n --------------      --------------"
	    << "\n |  Player 1  |      |  Player 2  |"
	    << "\n |------------|  VS  |------------|"
	    << "\n | "<< std::left  << std::setw(10) << type1 << " |"
	    << "      | "<< std::left  << std::setw(10) << type2 << " |"
	    << "\n | mark : " << mark1 << "   |"
	    << "      | mark : " << mark2 << "   |"
	    << "\n --------------      --------------";
}

char GameIoTicTacToeText::getInput(std::vector<char> choices) {
  std::string temp_ ;
  do {
    std::cin >> temp_;
    if (temp_ == "quit")
      exit(0);
  } while (std::find(choices.begin(), choices.end(), temp_[0]) == choices.end());
  return temp_[0];
}

char GameIoTicTacToeText::getInput() {
  std::string temp_ ;
  std::cin >> temp_;
  if (temp_ == "quit")
    exit(0);
  return temp_[0];
}

bool GameIoTicTacToeText::getYesNo() {
  std::vector<char> choices_;
  choices_.push_back('Y');
  choices_.push_back('y');
  choices_.push_back('N');
  choices_.push_back('n');
  std::cout << "(yes or no) :";
  switch (getInput(choices_)) {
  case 'Y':
  case 'y':
      return true;
  case 'N':
  case 'n':
      return false;
  }
}

void GameIoTicTacToeText::print(MoveLog moveLog) {
  std::vector<std::string> log_ = moveLog.getLog();
  std::cout << std::endl;
  for (int i = 0; i < log_.size(); ++i) {
    std::cout << "Move (" << i + 1 << ")" << log_[i] << std::endl; 
  }
}

int GameIoTicTacToeText::getHumanMove(GameBoardTTT gameBoardTTT) {
  int rtn_;
  char input_;
  std::vector<int> moves_ = gameBoardTTT.getAvailableSpaces();
  std::string prompt_ = "Please enter one of the following space numbers ( ";
  std::string temp_;
  for (int i = 0; i < moves_.size(); ++i) {
    temp_ = moves_[i] + '1';
    prompt_.append(temp_);
    prompt_.append(" ");
  }
  prompt_.append(") or type 'quit' to exit :");
  print("\n");
  do {
    print(prompt_);
    input_ = getInput();
    rtn_ = input_ - '1';
  } while (!gameBoardTTT.validMove(rtn_));
  return rtn_;
}

void GameIoTicTacToeText::print(GameMenu menu) {
  std::cout << std::endl << menu.getTitle() << std::endl;
  
  for (int i = 0; i < menu.size(); ++i)
    std::cout << "  " << i + 1 << " " << menu.item(i) << std::endl;
  print("Select an option (or type quit to exit): ");
}
