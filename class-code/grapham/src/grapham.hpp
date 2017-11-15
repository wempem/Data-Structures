#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template<class W>
class GraphAM {
    private:
        std::vector<std::vector<W> > mGraph;
    public:
        GraphAM();
        GraphAM(const int numberOfVertices);
        void clearEdges();
        void addVertex();
        void deleteVertex();
        void addEdge(const int start, const int end, const W weight);
        W adjacentWeight(const int start, const int end);
        void print();
        // Traversal?
        void breadthFirstTraversal(void (*visit)(const int node));
};

/*
 * You must include the cpp when using templates for out class.
 */
#include "grapham.cpp"

#endif
