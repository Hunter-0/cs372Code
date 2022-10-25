#include <vector>
#include <iostream>
using namespace std;

struct edge {  //Write a function, and test scripts for that function, that given a reference to a graph and a vector of integers that defines a path 
                // through the graph, returns a boolean value of true if the path is a simple cycle in the graph.    
                //NOTE: remember that a cycle is a path that begins and ends at the same node in the graph and has no loops within the cycle 
                //(visits each node at least once.   So, you have to verify it's a valid path and that the path never visits a node more than once.
    int node1;
    int node2;
};

struct graph {
    vector<int> nodes;
    vector<edge> edges;
};


string is_path_cycle(graph gGraph, vector<int> path) {

    string is_cycle = "It is not a cycle";
    std::cout << "Graph nodes: " << gGraph.nodes.size() << std::endl;
    std::cout << "Graph edges: " << gGraph.edges.size() << std::endl;
    std::cout << "Path length: " << path.size() << std::endl;

    for (int i = 0; i < path.size(); i++){


    }



    if ((path.size()==5)){
    is_cycle = "It is a cycle";
    }

    return is_cycle;
}


int main() {

    graph gGraph = {
        {0,1,2,3,4,5,6,7,8,9},
        {{0,1},{2,1},{6,0},{8,6},{8,1}}
    };

    vector<int> path1{1,0,8,8,1};
    vector<int> path2{2,6,6,1,1};

    std::cout << "Path 1 result: " << is_path_cycle(gGraph, path1) << std::endl;
    std::cout << "Path 2 result: " << is_path_cycle(gGraph, path2) << std::endl;

    return 0;
}
