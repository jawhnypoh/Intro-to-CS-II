# Makefile for Lab 3

hw2.exe: driver.o deck.o cards.o hand.o player.o dealer.o game.o
	g++ driver.o deck.o cards.o hand.o player.o dealer.o game.o -o hw2.exe
driver:
	g++ -c driver.cpp
deck:
	g++ -c deck.cpp
cards:
	g++ -c cards.cpp
hand:
	g++ -c hand.cpp
player:
	g++ -c player.cpp
dealer:
	g++ -c dealer.cpp
game:
	g++ -c game.cpp

clean:
	rm -f *.o *.out *.exe
