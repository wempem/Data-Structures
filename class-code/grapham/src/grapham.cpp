#ifdef GRAPH_H
#include "grapham.hpp"

#include <iostream>
#include <queue>
#include <set>

template<class W>
GraphAM<W>::GraphAM() {
}

//std::vector<std::vector<W> > mGraph;
template<class W>
GraphAM<W>::GraphAM(const int numberOfVertices) {

    mGraph.resize(numberOfVertices);

    for (int i = 0; i < numberOfVertices; i++) {
        mGraph[i].resize(numberOfVertices);
    }

    clearEdges();
}

template<class W>
void GraphAM<W>::clearEdges() {
    std::cout << "\n";
    for (int i = 0; i < mGraph.size(); i++) {
        for (int j = 0; j < mGraph[i].size(); j++) {
            mGraph[i][j] = -1;
            if (i == j) {
                mGraph[i][j] = 0;
            }
        }
    }
}

template<class W>
void GraphAM<W>::print() {
    for (int i = 0; i < mGraph.size(); i++) {
        for (int j = 0; j < mGraph[i].size(); j++) {
            std::cout << mGraph[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

template<class W>
void GraphAM<W>::addVertex() {
}

template<class W>
void GraphAM<W>::deleteVertex() {
}

template<class W>
void GraphAM<W>::addEdge(const int start, const int end, const W weight) {
    mGraph[start][end] = weight;
}

template<class W>
W GraphAM<W>::adjacentWeight(const int start, const int end) {
    return mGraph[start][end];
}

template<class W>
void GraphAM<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    std::queue<int> queue;
    std::set<int> isVisited;

    queue.push(0);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        if (isVisited.find(node) != isVisited.end()) {
            // oop we already visited it, continue
            continue;
        }

        // 1) visit the node
        visit(node);

        // 2) add node to the set of visited nodes
        isVisited.insert(node);

        // 3) add all nodes to the queue that have not been visited
        // Find the edges that have weights and add then to the queue if they haven't been visited.
        for (int i = 0; i < mGraph[node].size(); i++) {
            if (i != node  // Don't add self
                    && mGraph[node][i] > -1 // Must have a wieght
                    && isVisited.find(i) == isVisited.end()) // Must not have been visited
            {
                queue.push(i);
            }
        }


        // Now if the queue is empty check if there are other nodes that we need to add
        for (int i = 0; i < mGraph.size() && queue.empty(); i++) { // i represents the node/vertex number
            if (isVisited.find(i) == isVisited.end()) {
                queue.push(i);
            }
        }
    }
}

#endif
