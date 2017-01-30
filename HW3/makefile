# Makefile for Assignment 3

zoo.exe: driver.o animal.o tiger.o pb.o penguin.o kangaroo.o zoo.o
	g++ driver.o animal.o tiger.o pb.o penguin.o kangaroo.o zoo.o -o zoo.exe
driver:
	g++ -c driver.cpp
animal:
	g++ -c animal.cpp
tiger:
	g++ -c tiger.cpp
pb:
	g++ -c pb.cpp
penguin:
	g++ -c penguin.cpp
kangaroo:
	g++ -c kangaroo.cpp
zoo:
	g++ -c zoo.cpp


clean:
	rm -f *.o *.out *.exe
