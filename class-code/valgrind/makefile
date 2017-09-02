run: main
	./main

main: main.cpp
	g++ -g -Wall main.cpp -o main

valgrind: main
	valgrind ./main

clean:
	rm main
