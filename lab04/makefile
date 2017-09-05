MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
CFLAGS=-g -I src/
.PHONY: clean test all

all:
	g++ -o arrays-test $(CFLAGS) ${SRCS} ${MAIN}

run: all
	./arrays-test

%test:
	cxxtestgen --runner=ErrorPrinter -o test/test-runner.cpp test/$@.cpp ${SRCS}
	g++ ${CFLAGS} test/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

clean:
	rm -rf arrays-test test/test-runner.cpp test-runner
