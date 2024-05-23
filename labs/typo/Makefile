CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: main.o Heap.o Point.o WordList.o
	${CXX} $(CXXFLAGS) -o $@ $+

main.o: main.cpp WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

# test: test.o Heap.o Point.o WordList.o
# 	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp
	${CXX} $(CXXFLAGS) -c -o $@ $<

Heap.o: Heap.cpp Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Point.o: Point.cpp Point.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<

WordList.o: WordList.cpp WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test main.o Heap.o Point.o WordList.o
