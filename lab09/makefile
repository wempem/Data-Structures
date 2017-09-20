MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
CFLAGS=-g -I src/
.PHONY: clean test all

all:
	g++ -o sll-test $(CFLAGS) ${SRCS} ${MAIN}

run: all
	./sll-test

%test:
	cxxtestgen --runner=ErrorPrinter -o tests/test-runner.cpp tests/$@.cpp ${SRCS}
	g++ ${CFLAGS} tests/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

clean:
	rm -rf sll-test tests/test-runner.cpp test-runner
