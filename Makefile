all: rm.o rm

rm: rm.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o rm rm.o

rm.o: rm.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c rm.cpp
clean:
	rm rm.o
	rm rm