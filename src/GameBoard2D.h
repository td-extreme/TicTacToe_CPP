// GameBoard2D.h
// Tyler Decker

#ifndef _GameBoard2D_H
#define _GameBoard2D_H

#include<iostream>
#include<string>
template <class T>
class GameBoard2D {

 private:
  T ** board;
  int rowsize;
  int colsize;

 public:

  GameBoard2D(int Row, int Col);
  GameBoard2D(const GameBoard2D<T> &object);
  GameBoard2D<T> & operator= (const GameBoard2D & other);
  ~GameBoard2D();

  int colSize() {return colsize;}
  int rowSize() {return rowsize;}
  int size() {return rowsize * colsize;}
  void clear(T fillValue);
  T getSpace(int row, int col);
  T getSpace(int space);
  void setSpace(int row, int col, T value);
  void setSpace(int space, T value);
  std::string toString();
  const std::string toStringC();
  void print();
  int toRow(int space);
  int toCol(int space);
  void swap(int row1, int col1, int row2, int col2);
  void swap(int space1, int space2);
  
};
#include "GameBoard2D.tpp"
#endif
