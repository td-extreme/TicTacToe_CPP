// Tyler Decker
// GameMenu.cpp
#include "GameMenu.h"

GameMenu::GameMenu(std::string title): title(title) {}

std::string GameMenu::getTitle() {
  return title;
}

int GameMenu::size() {
  return menu.size();
}

std::string GameMenu::item(int index){
  if ( index < 0 || index > size() )
    return "";
  return menu[index];
}

std::vector<char> GameMenu::choices() {
  std::vector<char> rtn_;
  for (int i = 0; i < menu.size(); ++i)
    rtn_.push_back(i + '1');
  return rtn_;
}

void GameMenu::add(std::string menuOption) {
  menu.push_back(menuOption);
}
