CC=g++
CFLAGS=-c -Wall

all: compile

compile: main.o board.o piecetype.o game.o
	$(CC) main.o board.o piecetype.o game.o -o tictactoe
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

board.o: board.cpp
	$(CC) $(CFLAGS) board.cpp

piecetype.o: piecetype.cpp	
	$(CC) $(CFLAGS) piecetype.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

clean:
	rm -rf *o tictactoe