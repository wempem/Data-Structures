#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "grapham.hpp"

void print(const int node) {
    printf("%d\n", node);
}

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            GraphAM<int> graph(5);
            graph.addEdge(0, 3, 17);
            graph.addEdge(0, 4, 11);
            graph.addEdge(1, 0, 14);
            graph.addEdge(1, 3, 7);
            graph.addEdge(1, 4, 11);
            graph.addEdge(2, 1, 15);
            graph.addEdge(3, 0, 19);
            graph.addEdge(4, 3, 11);
            graph.print();
            graph.breadthFirstTraversal(print);
        }
};

