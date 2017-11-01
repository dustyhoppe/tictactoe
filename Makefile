CC=g++
CFLAGS=-c -Wall -std=c++11

all: compile

compile: main.o board.o piecetype.o game.o console.o
	$(CC) main.o board.o piecetype.o game.o console.o -o tictactoe
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

board.o: board.cpp
	$(CC) $(CFLAGS) board.cpp

piecetype.o: piecetype.cpp	
	$(CC) $(CFLAGS) piecetype.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

console.o: console.cpp
	$(CC) $(CFLAGS) console.cpp

clean:
	rm -rf *o tictactoe