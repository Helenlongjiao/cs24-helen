CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: Board.o game-check.o Move.o
	${CXX} $(CXXFLAGS) -o $@ $+

Board.o: Board.cpp Board.h Move.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<


game-check.o: game-check.cpp Move.h Board.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Move.o: Move.cpp Move.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test Board.o game-check.o Move.o test move-check.o
