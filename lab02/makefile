all: main
main: main.o list.o node.o
	g++ -g -Wall src/objs/list.o src/objs/main.o src/objs/node.o -o main
main.o: src/main.cpp src/list.h src/node.h 
	g++ -c -Wall src/main.cpp -o src/objs/main.o
list.o: src/list.cpp src/list.h src/node.h
	g++ -c -Wall src/list.cpp -o src/objs/list.o
node.o: src/node.cpp src/node.h
	g++ -c -Wall src/node.cpp -o src/objs/node.o
valgrind:
	valgrind ./main
clean:
	rm src/objs/*.o main

