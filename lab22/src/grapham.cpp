#ifdef GRAPHAM_H

#include <iostream>
#include <queue>

template<class W>
GraphAM<W>::GraphAM() {
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
}

template<class W>
int GraphAM<W>::addVertices(const int vertices) {
    // Create a new graph with mLen + vertices nodes.
    // Initialize the NEW elements.
    // Deep copy the old graph to the new graph.
    // Set mLen = mLen + vertices
    // Free (delete) the old graph.

    // OR just use a vector!
}

template<class W>
bool GraphAM<W>::removeVertex(int idx) {
    // Free mMatrix[idx];
    // Move all elements below idx up one (mMatrix[idx] = mMatrix[idx+1] for the rest of the Matrix.  Do for all elements for all element > idx.
    // Fix each elements of the mMatrix[i]. IE: mMatrix[i][idx] = mMatrxi[i][idx+1]-- you have to do for all elements > idx.
    // mLen = mLen - 1;
}

template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
    // You may assume a directed graph.
    return true;
}

template<class W>
bool GraphAM<W>::removeEdge(const int start, const int end) {
    return true;
}

template<class W>
W GraphAM<W>::adjacent(const int start, const int end) {
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node),
                int *visited, const int cVertex) {
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node)) {
}

template<class W>
void GraphAM<W>::breadthFirstTraversal(void (*visit)(const int node)) {
}

template<class W>
void GraphAM<W>::print() const {
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
