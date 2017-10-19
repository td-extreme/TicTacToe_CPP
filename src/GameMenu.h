// Tyler Decker
// GameMenu.h

#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include <vector>
#include <string>

class GameMenu {
 private:
  std::string title;
  std::vector<std::string> menu;
  
 public:
  GameMenu(std::string title);
  std::string getTitle();
  std::vector<std::string> getMenu();
  int size();
  std::string item(int index);
  std::vector<char> choices();
  void add(std::string menuOption);
};
#endif
