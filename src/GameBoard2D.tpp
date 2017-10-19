// GameBoard2D.tpp
// Tyler Decker

template<class T>
GameBoard2D<T>::GameBoard2D(int Row, int Col): rowsize(Row), colsize(Col){
  // allocate memory for the board
  board = new T * [rowsize];
  for(int i = 0; i < rowsize; ++i) {
    board[i] = new T[colsize];
  }
}
	  
template<class T>
GameBoard2D<T>::~GameBoard2D() {
  // free up memory for the board
  for (int i =0; i < rowSize(); ++i) {
    delete [] board[i];
  }
  delete [] board;
}

template<class T>
GameBoard2D<T>::GameBoard2D(const GameBoard2D<T> &object) {
  this->rowsize = object.rowsize;
  this->colsize = object.colsize;
  this->board = new T * [rowsize];
  for(int i = 0; i < rowsize; ++i) 
    this->board[i] = new T[colsize];
  for(int i = 0; i < rowsize; ++i) 
    for(int j = 0; j < colsize; ++j) {
      this->board[i][j] = object.board[i][j];
    }
}


template<class T>
GameBoard2D<T> & GameBoard2D<T>::operator= (const GameBoard2D & other) {
  if (this == &other)
    return *this;
  for (int i = 0; i < rowSize(); ++i) {
    delete [] board[i];
    }
  delete [] board;
  
  rowsize = other.rowsize;
  colsize = other.colsize;
  
  board = new T * [rowsize];
  for (int i = 0; i < rowSize(); ++i) {
    board[i] = new T[colsize];
  }
  for (int i = 0; i < rowSize(); ++i)
    for (int j = 0; j < colSize(); ++j) {
      board[i][j] = other.board[i][j];
    } 
  return *this;  
}

template<class T>
void GameBoard2D<T>::clear(T fillValue) {
  for (int i = 0; i < rowSize();  ++i) 
    for (int j = 0; j < colSize(); ++j){
      board[i][j] = fillValue;
    }
}

template<class T>
T GameBoard2D<T>::getSpace(int row, int col) {
  return board[row][col];
}
template<class T>
T GameBoard2D<T>::getSpace(int space) {
  return getSpace(toRow(space), toCol(space));
}
template<class T>
void GameBoard2D<T>::setSpace(int row, int col, T value) {
  board[row][col] = value;
}
template<class T>
void GameBoard2D<T>::setSpace(int space, T value) {
  setSpace(toRow(space), toCol(space), value);
}

template<class T>
void GameBoard2D<T>::swap(int row1, int col1, int row2, int col2) {
  T temp_;
  temp_ = board[row1][col1];
  board[row1][col1] = board[row2][col2];
  board[row2][col2] = temp_;
}

template<class T>
void GameBoard2D<T>::swap(int space1, int space2) {
  swap(toRow(space1), toCol(space1), toRow(space2), toCol(space2));
}

template<class T>
std::string GameBoard2D<T>::toString() {
  std::string rtnString;
  std::string temp_;
  int i, j, k;
  rtnString.append("\n ");
  for (k = 0; k < colSize(); ++k) {
    rtnString.append("--- "); 
  }
  for (i = 0; i < rowSize(); ++i) {
        rtnString.append("\n|");
    for (j = 0; j < colSize(); ++j) { 
        rtnString.append(" ");
        temp_ = getSpace(i, j);
        rtnString.append(temp_);
        rtnString.append(" |");            
    }
    rtnString.append("\n ");
    for (k = 0; k < colSize(); ++k) {
      rtnString.append("--- "); 
    }
  }
  return rtnString;
}

template<class T>
void GameBoard2D<T>::print() {
  for (int i = 0; i < rowSize(); ++i)
    for (int j = 0; j < colSize(); ++j)
      std::cout << "board [" << i << ", " << j << "] = " << getSpace(i, j) << " ; " << std::endl;
  

}

template<class T>
int GameBoard2D<T>::toRow(int space) {
    return space / colsize;
}

template<class T>
int GameBoard2D<T>::toCol(int space) {
    return space % colsize;
}


