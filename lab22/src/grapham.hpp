#ifndef GRAPHAM_H
#define GRAPHAM_H

/* This class represents a weighted directed graph via an adjacency matrix.
 * Vertices are given an index, starting from 0 and ascending
 * Class W : W represent the weight that can be associated with an edge.
 * We will not weight the vertices.
 */
#include <vector>
#include <set>
template<class W>
class GraphAM {
    private:
	std::vector<std::vector<W> > mGraph;
        void depthFirstTraversal(void (*visit)(const int node),
                int *visited, const int cVertex);
    	void depthFirstTraversal(void (*visit)(const int node), int node, 
				const int std::set<int> &visited);
    public:
        /* Initialize an empty graph. */
        GraphAM();

        /* Initialize the Graph with a fixed number of vertices. */
        GraphAM(const int vertices);

        /* Deconstructor shall free up memory */
        ~GraphAM();

        /* Adds amt vertices to the graph. */
        int addVertices(int amt);

        /* Removes a vertex. 
         * return whether successful or not
         */
        bool removeVertex(int idx);

        /* Adds an edge with weight W to the graph. */
        bool addEdge(const int start, const int end, const W &weight);

        /* 
         * Remove edge from graph.
         */
        bool removeEdge(const int start, const int end);

        void depthFirstTraversal(void (*visit)(const int node));
        void breadthFirstTraversal(void (*visit)(const int node));

	void clearEdges();        /*
         * Return adjacent weight from start to end (or -1 if they are
         * not adjacent.
         */
        W adjacent(const int start, const int end);

        /* Run Dijkstra's Shortest Path to find the shortest path from start
         * to end and returning that smallest weight.
         * return -1 if a path does not exist!
         */
        W dijkstraShortestPath(const int start, const int end);

        /* Print out the Graph */
        void print() const;

};

#include "grapham.cpp"

#endif
