CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: test

test: List.o Counter.o Iterator.o main.o
	${CXX} $(CXXFLAGS) -o $@ $+

char-count: List.o Counter.o Iterator.o char-count.o
	${CXX} $(CXXFLAGS) -o $@ $+

word-count: List.o Counter.o Iterator.o word-count.o
	${CXX} $(CXXFLAGS) -o $@ $+

List.o: List.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<


Counter.o: Counter.cpp Counter.h List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Iterator.o: Iterator.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp Counter.h

# char-count.o: char-count.cpp Counter.h

# word-count.o: word-count.cpp Counter.h

clean:
	rm -f test  List.o Counter.o Iterator.o
