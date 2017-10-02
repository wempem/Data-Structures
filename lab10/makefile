MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
CFLAGS=-g -I src/
.PHONY: clean test all

all:
	g++ -o sq-test $(CFLAGS) ${SRCS} ${MAIN}

run: all
	./sq-test

%test:
	cxxtestgen --runner=ErrorPrinter -o tests/test-runner.cpp tests/$@.cpp ${SRCS}
	g++ ${CFLAGS} tests/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

clean:
	rm -rf sq-test tests/test-runner.cpp test-runner
