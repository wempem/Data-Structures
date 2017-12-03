#ifdef GRAPHAL_H
#include <iostream>
#include <set>
#include <queue>
template<class W>
GraphAL<W>::GraphAL() {
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
	mGraph.resize(vertices);
	clearEdges();
}
template <class W>
void GraphAL<W>::clearEdges() {
    for (int i = 0; i < mGraph.size(); i++) {
        mGraph[i].clear();
    }
}


/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
	std::pair<int, W> toAdd(end, weight);
	mGraph[start].push_back(toAdd);
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
	if(start == end){
		return false;
	}
	for(typename std::list<std::pair<int,W> >::iterator it = mGraph[start].begin();
		it != mGraph[start].end(); ++it){
		if(it->first == end){
			mGraph[start].erase(it);
			return true;
		}	
	}
	return false;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
	if(amt = 0 || NULL){
		return;
	}
	if(amt < 0){
		return;
	}
	int newSize = mGraph.size() + amt;
	mGraph.resize(newSize);		
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
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

/* Removes a vertex. 
 * return wheter sucessful or not
 */
template<class W>
bool GraphAL<W>::removeVertex(int idx) {
	if(idx < 0 || idx >= mGraph.size()){
		return false;
 	}
	mGraph.erase(mGraph.begin() + idx);
	for(int i = 0; i < mGraph.size(); i++){
	for(typename std::list<std::pair<int , W> >::iterator it = mGraph[i].begin(); it != mGraph[i].end(); it++){
		if(it->first == idx){
			mGraph[i].erase(it);
		}
 
		}
	}
	return true;
}

template<class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), int node,
        std::set<int> &visited) {
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

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
	std::set<int> visited;
	for (int i = 0; i < mGraph.size(); i++) {
		if (visited.find(i) == visited.end()) {
         		depthFirstTraversal(visit, i, visited);
     		}
 	}
}

template <class W>
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
GraphAL<W>::~GraphAL() {
}

template<class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
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
                    && mGraph[node].first > -1 // Must have a wieght
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
#endif
