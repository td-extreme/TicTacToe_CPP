// Tyler Decker
// MoveLog.h
#include <string>
#include <vector>

#ifndef _MOVELOG_H
#define _MOVELOG_H

class MoveLog {
 private:
  std::vector<std::string> log;
 public:
  void add(int space, char mark);
  std::vector<std::string> getLog();
  void clear();
};
#endif
