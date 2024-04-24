CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: Node.o Tree.o
	${CXX} $(CXXFLAGS) -o $@ $+

Node.o: Node.cpp Node.h
	${CXX} $(CXXFLAGS) -c -o $@ $<


Tree.o: Tree.cpp Tree.h Node.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test Tree.o Node.o test
