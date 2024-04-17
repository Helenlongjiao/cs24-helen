CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: move-check.o Move.o
	${CXX} $(CXXFLAGS) -o $@ $+


Move.o: Move.cpp Move.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

move-check.o: move-check.cpp
	${CXX} $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f test Move.o move-check.o test
