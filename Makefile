# file: Makefile
# Tyler Decker
# Feb 2nd 2016
#

HOME 	= .
SRC 	= $(HOME)/src
BUILD	= $(HOME)/build
TEST	= $(HOME)/test
TARGET  = $(HOME)/bin

CC	= g++ -std=c++11 -g
CFLAGS	= # -Wall -Wextra
OFLAGS  = -c
LIB	= -lcppunit
INC	= -I$(SRC) -I$(TEST) -I$(BUILD)

all : TestMoveLog.x TestGameMenu.x TestGameBoard2D.x TestGameBoardTTT.x TestTicTacToePlayer.x TestTicTacToeGame.x TestGameIoTicTacToe.x ttt.x 

run	: ttt.x
	./bin/ttt.x

ttt.x :	ttt.o  TicTacToeGame.o GameBoardTTT.o TicTacToePlayer.o GameIoTicTacToe.o GameMenu.o PlayerSettingsMenu.o MoveLog.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/ttt.x $(BUILD)/ttt.o $(BUILD)/GameBoardTTT.o $(BUILD)/TicTacToePlayer.o $(BUILD)/TicTacToeGame.o $(BUILD)/GameIoTicTacToe.o $(BUILD)/GameMenu.o $(BUILD)/PlayerSettingsMenu.o $(BUILD)/MoveLog.o

ttt.o : $(SRC)/main.cpp 
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/ttt.o $(SRC)/main.cpp

runTests : runTestMoveLog runTestGameMenu RunTestGameBoard2D RunTestGameBoardTTT runTestTicTacToePlayer runTestTicTacToeGame runTestGameIoTicTacToe

runTestMoveLog : TestMoveLog.x
	$(TARGET)/TestMoveLog.x

runTestTicTacToeGame : TestTicTacToeGame.x
	$(TARGET)/TestTicTacToeGame.x

runTestGameMenu : TestGameMenu.x
	$(TARGET)/TestGameMenu.x

runTestGameIoTicTacToe : TestGameIoTicTacToe.x
	$(TARGET)/TestGameIoTicTacToe.x

runTestTicTacToePlayer : TestTicTacToePlayer.x
	$(TARGET)/TestTicTacToePlayer.x

TestPlayerSettingsMenu.x : TestPlayerSettingsMenu.o PlayerSettingsMenu.o GameBoardTTT.o TicTacToePlayer.o GameMenu.o MoveLog.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestPlayerSettingsMenu.x $(BUILD)/TestPlayerSettingsMenu.o $(BUILD)/GameIoTicTacToe.o $(BUILD)/GameBoardTTT.o $(BUILD)/TicTacToePlayer.o $(BUILD)/PlayerSettingsMenu.o $(BUILD)/GameMenu.o $(BUILD)/MoveLog.o $(LIB)

TestPlayerSettingsMenu.o : $(TEST)/TestPlayerSettingsMenu.cpp $(TEST)/TestPlayerSettingsMenu.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestPlayerSettingsMenu.o  $(TEST)/TestPlayerSettingsMenu.cpp

PlayerSettingsMenu.o : $(SRC)/PlayerSettingsMenu.h $(SRC)/PlayerSettingsMenu.cpp $(SRC)/TicTacToePlayer.h $(SRC)/GameIoTicTacToe.h $(SRC)/GameMenu.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/PlayerSettingsMenu.o $(SRC)/PlayerSettingsMenu.cpp

TestTicTacToeGame.x : TestTicTacToeGame.o GameBoardTTT.o TicTacToePlayer.o GameIoTicTacToe.o MoveLog.o TicTacToeGame.o GameMenu.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestTicTacToeGame.x $(BUILD)/TestTicTacToeGame.o $(BUILD)/GameBoardTTT.o $(BUILD)/TicTacToePlayer.o $(BUILD)/GameIoTicTacToe.o $(BUILD)/MoveLog.o $(BUILD)/TicTacToeGame.o $(BUILD)/GameMenu.o $(LIB)

TestTicTacToeGame.o : $(TEST)/TestGameIoTicTacToe.cpp $(TEST)/TestGameIoTicTacToe.h $(SRC)/GameBoard2D.h $(SRC)/GameBoardTTT.h $(SRC)/TicTacToePlayer.h $(SRC)/GameIoTicTacToe.h $(SRC)/MoveLog.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestTicTacToeGame.o $(TEST)/TestTicTacToeGame.cpp

TicTacToeGame.o : $(SRC)/TicTacToeGame.h $(SRC)/TicTacToeGame.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TicTacToeGame.o $(SRC)/TicTacToeGame.cpp

TestGameIoTicTacToe.x : TestGameIoTicTacToe.o GameIoTicTacToe.o GameBoardTTT.o TicTacToePlayer.o GameMenu.o MoveLog.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestGameIoTicTacToe.x $(BUILD)/TestGameIoTicTacToe.o $(BUILD)/GameIoTicTacToe.o $(BUILD)/GameBoardTTT.o $(BUILD)/TicTacToePlayer.o $(BUILD)/GameMenu.o $(BUILD)/MoveLog.o $(LIB)

TestGameIoTicTacToe.o : $(TEST)/TestGameIoTicTacToe.cpp $(TEST)/TestGameIoTicTacToe.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestGameIoTicTacToe.o  $(TEST)/TestGameIoTicTacToe.cpp

GameIoTicTacToe.o :  $(SRC)/GameIoTicTacToe.h $(SRC)/GameIoTicTacToe.cpp $(SRC)/GameBoardTTT.h $(SRC)/GameBoard2D.h $(SRC)/GameMenu.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/GameIoTicTacToe.o $(SRC)/GameIoTicTacToe.cpp

TestTicTacToePlayer.x : TestTicTacToePlayer.o GameBoardTTT.o TicTacToePlayer.o GameIoTicTacToe.o GameMenu.o MoveLog.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestTicTacToePlayer.x $(BUILD)/TestTicTacToePlayer.o $(BUILD)/GameBoardTTT.o $(BUILD)/TicTacToePlayer.o $(BUILD)/GameIoTicTacToe.o $(BUILD)/GameMenu.o $(BUILD)/MoveLog.o $(LIB)

TestTicTacToePlayer.o : $(TEST)/TestTicTacToePlayer.cpp $(TEST)/TestTicTacToePlayer.h 
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestTicTacToePlayer.o  $(TEST)/TestTicTacToePlayer.cpp

TicTacToePlayer.o : $(SRC)/TicTacToePlayer.cpp 
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TicTacToePlayer.o $(SRC)/TicTacToePlayer.cpp

RunTestGameBoardTTT : TestGameBoardTTT.x
	$(TARGET)/TestGameBoardTTT.x

TestGameBoardTTT.x : TestGameBoardTTT.o GameBoardTTT.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestGameBoardTTT.x  $(BUILD)/TestGameBoardTTT.o $(BUILD)/GameBoardTTT.o $(LIB)

TestGameBoardTTT.o : $(TEST)/TestGameBoardTTT.cpp $(TEST)/TestGameBoardTTT.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestGameBoardTTT.o  $(TEST)/TestGameBoardTTT.cpp

GameBoardTTT.o	: $(SRC)/GameBoardTTT.h $(SRC)/GameBoardTTT.cpp $(SRC)/GameBoard2D.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/GameBoardTTT.o $(SRC)/GameBoardTTT.cpp

TestGameMenu.x : TestGameMenu.o GameMenu.o GameIoTicTacToe.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestGameMenu.x $(BUILD)/TestGameMenu.o $(BUILD)/GameMenu.o $(LIB)

TestGameMenu.o : $(TEST)/TestGameMenu.h $(TEST)/TestGameMenu.cpp $(SRC)/GameMenu.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestGameMenu.o $(TEST)/TestGameMenu.cpp

GameMenu.o : $(SRC)/GameMenu.h $(SRC)/GameMenu.cpp $(SRC)/GameIoTicTacToe.h $(SRC)/TicTacToePlayer.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/GameMenu.o $(SRC)/GameMenu.cpp

RunTestGameBoard2D : TestGameBoard2D.x
	$(TARGET)/TestGameBoard2D.x

TestGameBoard2D.x : TestGameBoard2D.o 
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestGameBoard2D.x  $(BUILD)/TestGameBoard2D.o $(LIB)

TestGameBoard2D.o : $(TEST)/TestGameBoard2D.cpp $(TEST)/TestGameBoard2D.h  $(SRC)/GameBoard2D.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestGameBoard2D.o  $(TEST)/TestGameBoard2D.cpp

TestMoveLog.x : TestMoveLog.o MoveLog.o
	$(CC) $(CFLAGS) $(INC) -o $(TARGET)/TestMoveLog.x $(BUILD)/TestMoveLog.o $(BUILD)/MoveLog.o $(LIB)

TestMoveLog.o : $(TEST)/TestMoveLog.h $(TEST)/TestMoveLog.cpp $(SRC)/MoveLog.h
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/TestMoveLog.o $(TEST)/TestMoveLog.cpp

MoveLog.o : $(SRC)/MoveLog.h $(SRC)/MoveLog.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILD)/MoveLog.o $(SRC)/MoveLog.cpp

clean:
	@echo " Clean";
	@echo " rm $(BUILD)/*.o rm $(TARGET)/*.x "; rm $(BUILD)/*.o $(TARGET)/*.x;
