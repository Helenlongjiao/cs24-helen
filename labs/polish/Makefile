CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: main.o AST.o stack.o Nodes.o
	${CXX} $(CXXFLAGS) -o $@ $+

Nodes.o: Nodes.cpp Nodes.h
	${CXX} $(CXXFLAGS) -c -o $@ $<


AST.o: AST.cpp Nodes.h Stack.h AST.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

stack.o: Stack.cpp Stack.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test main.o AST.o stack.o Nodes.o
