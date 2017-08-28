CFLAGS=-g -Wall
run: all
	./sum.exe

all: main.o sum.o
	g++ $(CFLAGS) main.o sum.o -o sum.exe


# This is a comment
main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

sum.o: sum.cpp
	g++ $(CFLAGS) -c sum.cpp

clean:
	rm *.o sum.exe
