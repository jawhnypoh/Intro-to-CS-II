# Makefile for Assignment 4

hw4: driver.o events.o pit.o bats.o gold.o game.o wumpus.o room.o cave.o
	g++ driver.o events.o pit.o bats.o gold.o game.o wumpus.o room.o cave.o -o hw4
driver:
	g++ -c driver.cpp
events:
	g++ -c events.cpp
pit:
	g++ -c pit.cpp
bats:
	g++ -c bats.cpp
gold:
	g++ -c gold.cpp
game:
	g++ -c game.cpp
wumpus:
	g++ -c wumpus.cpp
room:
	g++ -c room.cpp
cave:
	g++ -c cave.cpp

clean:
	rm -f *.o *.out *.exe
