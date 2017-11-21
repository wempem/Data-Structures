#ifdef GRAPH_H
#include "graphal.hpp"

#include <iostream>
#include <queue>
#include <set>
#include <utility>

template<class W>
GraphAL<W>::GraphAL() {
}

//std::vector<std::vector<W> > mGraph;
template<class W>
GraphAL<W>::GraphAL(const int numberOfVertices) {
    mGraph.resize(numberOfVertices);
    clearEdges();
}

template<class W>
void GraphAL<W>::clearEdges() {
    for (int i = 0; i < mGraph.size(); i++) {
        mGraph[i].clear();
    }
}

template<class W>
void GraphAL<W>::print() {
    std::cout << "\n";
    for (int i = 0; i < mGraph.size(); i++) {
        std::cout << i << " = { ";
        for (typename std::list<std::pair<int, W> >::iterator it = mGraph[i].begin();
                it != mGraph[i].end(); ++it) {
            std::cout << "(->" << it->first << ", W=" << it->second << ") ";
        }
        std::cout << "}\n";
    }
}

template<class W>
void GraphAL<W>::addVertex() {
}

template<class W>
void GraphAL<W>::deleteVertex() {
}

template<class W>
void GraphAL<W>::addEdge(const int start, const int end, const W weight) {
    std::pair<int, W> toAdd(end, weight);
    mGraph[start].push_back(toAdd);
}

template<class W>
W GraphAL<W>::adjacentWeight(const int start, const int end) {
    if (start == end) {
        return 0;
    }
    for (typename std::list<std::pair<int, W> >::iterator it = mGraph[start].begin();
                it != mGraph[start].end(); ++it) {
        if (it->first == end) {
            return it->second;
        }
    }

    return -1;
}

template<class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
}

template<class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), int node, 
        std::set<int> &visited) {
    //1) Base case If node has been visited, return;
    if (visited.find(node) != visited.end()) {
        return;
    }

    // Now we know that node has not been visited.
    // 2) visit the node
    visit(node);
    // 3) Mark as visited
    visited.insert(node);

    // 4) Got to each child
    for (typename std::list<std::pair<int, W> >::iterator it = mGraph[node].begin();
                it != mGraph[node].end(); ++it) {
        // it represents a pointer to the child
        // 5) recurse!
        depthFirstTraversal(visit, it->first, visited);
    }
}

template<class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;
    for (int i = 0; i < mGraph.size(); i++) {
        if (visited.find(i) == visited.end()) {
            depthFirstTraversal(visit, i, visited);
        }
    }
}

#endif
