#include <vector>
#include <iostream>
using namespace std;
#include <vector>
#include <utility>
template <class N>
class Graph {
public:

	Graph() {};
	Graph(std::vector<N> nodes, std::vector<std::pair<N, N>> edges) {};
	~Graph() {};

	bool adjacent(N x, N y);
	std::vector<N> neighbors(N x);
	void addNode(N x);
	void addEdge(N x, N y);
	void deleteEdge(N x, N y);      
    
    void dfs(N x);
    void bfs(N y);
 
};

struct edge {      
    int node1;
    int node2;
};

struct graph {
    vector<int> nodes;
    vector<edge> edges;
};


string is_path_cycle(graph gGraph, vector<int> path) {

    std::cout << "Graph nodes: " << gGraph.nodes.size() << std::endl;
    std::cout << "Graph edges: " << gGraph.edges.size() << std::endl;
    std::cout << "Path length: " << path.size() << std::endl;

    for (int i = 0; i < path.size(); i++){
         void bfs(N y);

    }

}


int main() {

    graph gGraph = {
        {0,1,2,3,4,5,6,7,8,9},
        {{0,1},{2,1},{6,0},{8,6},{8,1}}
    };

    vector<int> path1{1,0,8,8,1};
    vector<int> path2{2,6,6,1,1};

    std::cout << "Person 1: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 2: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 3: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 4: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 5: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 6: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 7: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 8: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 9: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 10: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 11: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 12: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 13: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 14: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 15: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 16: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 17: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 18: " << is_path_cycle(gGraph, path2) << std::endl;
    std::cout << "Person 19: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Person 20: " << is_path_cycle(gGraph, path2) << std::endl;


    return 0;
}
