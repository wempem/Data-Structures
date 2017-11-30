#ifdef GRAPHAM_H
#include <vector>
#include <iostream>
#include <queue>
#include <set>
template<class W>
GraphAM<W>::GraphAM() {
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
	
	mGraph.resize(vertices);

	for (int i = 0; i < vertices; i++) {
		mGraph[i].resize(vertices);
	}

	clearEdges();
}
template <class W>
void GraphAM<W>::clearEdges(){

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
int GraphAM<W>::addVertices(const int vertices) {
    // Create a new graph with mLen + vertices nodes.
    // Initialize the NEW elements.
    // Deep copy the old graph to the new graph.
    // Set mLen = mLen + vertices
    // Free (delete) the old graph.

    // OR just use a vector!
	int newSize = vertices + mGraph.size();
	int index = mGraph.size();
	
	mGraph.resize(newSize);
	for(int i = 0; i <newSize; i++){
		mGraph[i].resize(newSize);
	}
	for(int i = index; i < mGraph.size(); i++){
		for(int j = 0; j <mGraph.size(); j++){
			mGraph[i][j] = -1;
			if(i == j){
				mGraph[i][j] = 0;
			} 	
		}
	}
	for(int i = 0; i <mGraph.size(); i++){
		for(int j = index; j < mGraph.size(); j++){
			mGraph[i][j] = -1;
			if(i ==j){
				mGraph[i][j] = 0;
			}
		}
	}

}


template<class W>
bool GraphAM<W>::removeVertex(int idx) {
    // Free mMatrix[idx];
    // Move all elements below idx up one (mMatrix[idx] = mMatrix[idx+1] for the rest of the Matrix.  Do for all elements for all element > idx.
    // Fix each elements of the mMatrix[i]. IE: mMatrix[i][idx] = mMatrxi[i][idx+1]-- you have to do for all elements > idx.
    // mLen = mLen - 1;
	if(idx < 0 || idx > mGraph.size()){
		return false;
	}
	for(int j = idx; idx < mGraph.size(); j++){
		for(int i = 0; i < mGraph.size(); i++){
			mGraph[j][i] = mGraph[j+1][i];
		}
	}
	for(int j = idx; j <mGraph.size(); j++){
		for(int i = 0; i < mGraph.size(); i++){
			mGraph[i][j] = mGraph[i][j+1];
		}	 
	}
	mGraph.resize(mGraph.size() - 1);
	return true;
}
template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
    // You may assume a directed graph.
	if(start == end){
		std::cout << "Can't overwrite";
		return false;
	}
	else{
		mGraph[start][end] = weight;
		return true;
	}
}

template<class W>
bool GraphAM<W>::removeEdge(const int start, const int end) {
	if(mGraph[start][end] != NULL){
		if(mGraph[start][end] == 0){
			return false;
		}
		else
			mGraph[start][end] = -1;
			return true;
	}
    return false;
}

template<class W>
W GraphAM<W>::adjacent(const int start, const int end) {
	return mGraph[start][end];
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node),
                int *visited, const int cVertex) {
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node)) {
	std::set<int> isVisited;
	std::queue<int> queue;
	
	
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

        // 3) add all nodes to the queue that have not been visite
        // Find the edges that have weights and add then to the qu
        for (int i = 0; i < mGraph[node].size(); i++) {
            if (i != node  // Don't add self
                    && mGraph[node][i] > -1 // Must have a wieght
                    && isVisited.find(i) == isVisited.end()) // Mu
            {
                queue.push(i);
            }
        }


        // Now if the queue is empty check if there are other node
        for (int i = 0; i < mGraph.size() && queue.empty(); i++) {
            if (isVisited.find(i) == isVisited.end()) {
                queue.push(i);
            }
        }
    }
}

template<class W>
void GraphAM<W>::print() const {
	for (int i = 0; i < mGraph.size(); i++) {
     		for (int j = 0; j < mGraph[i].size(); j++) {
         		std::cout << mGraph[i][j] << "\t";
     		}
     		std::cout << "\n";
 	}	
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
