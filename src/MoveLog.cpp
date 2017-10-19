// Tyler Decker
// MoveLog.cpp
#include "MoveLog.h"

void MoveLog::add(int space, char mark) {
  std::string newMove_ = " - Player ";
  newMove_.push_back(mark);
  std::string newMove2_ = " played square # " + std::to_string(space);
  newMove_.append(newMove2_);
  log.push_back(newMove_);
}

void MoveLog::clear() {
  log.clear();
}

std::vector<std::string> MoveLog::getLog() {
  return log;
}
