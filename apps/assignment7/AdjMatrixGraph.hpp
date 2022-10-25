#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Graph.hpp"
using namespace std;

template <class N>
class AdjMatrixGraph: public Graph<N>  {
private:
    class NodeEntry {
    public:
        N node;
        int index;
    };
    const static int maxSize = 10;
    bool adjMatrix[maxSize][maxSize];
    NodeEntry *nodes[maxSize];
    int numNodes = 0;
    int findNodeInMatrix(N x){
        for (int j=0; j < numNodes; ++j)
        {
            if (x == nodes[j]->node)
            {
                return j;
            }
        }
        return -1;
    }
public:
    // Default constuctor, create empty
    AdjMatrixGraph()
    {
        for(int i = 0; i < maxSize; i++)
            for (int j=0; j < maxSize; j++)
            {
                adjMatrix[i][j] = false;
            }
    }
    // Add the nodes in the list to graph
    AdjMatrixGraph(vector<N> newNodes, vector<pair<N,N>> newEdges)
    {
        adjMatrix = new NodeEntry[maxSize][maxSize];
        for (typename vector<N>::const_iterator it = newNodes.begin();
             it < newNodes.end();
             ++it)
        {
            NodeEntry ne = new NodeEntry();
            ne.node = *it;
            ne.index = numNodes;
            nodes[numNodes] = ne;
            adjMatrix[numNodes][numNodes] = true;
        }
        for (typename vector<pair<N,N>>::const_iterator it = newEdges.begin();
             it < newEdges.end();
             ++it)
        {
            pair<N,N> edge = *it;
            int sourceIndex = findNodeInMatrix(edge.first);
            int destIndex = findNodeInMatrix(edge.second);
            if (sourceIndex != -1)
            {
                if (destIndex != -1)
                {
                    adjMatrix[sourceIndex][destIndex] = true;
                }
            }
        }
    }

    // Clean up behind ourselves
    ~AdjMatrixGraph() {};
    
    bool adjacent(N x, N y)
    {
        bool result = false;
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            bool xy = adjMatrix[xIndex][yIndex];
            bool yx = adjMatrix[yIndex][xIndex];
            result = xy && yx;
        }
        return(result);
    }

    vector<N> neighbors(N x)
    {
        vector<N> *v = new vector<N>();
        int xIndex = findNodeInMatrix(x);
        if (xIndex != -1)
        {
            for (int i=0; i < numNodes; ++i) {
                if (adjMatrix[xIndex][i] == true) {
                    v->push_back(nodes[i]->node);
                }
            }
        }
        return *v;
    }
    void addNode(N node)
    {
        NodeEntry *ne = new NodeEntry();
        ne->node = node;
        ne->index = numNodes;
        nodes[numNodes] = ne;
        adjMatrix[numNodes][numNodes] = true;
        numNodes++;

    }
    void addEdge(N x, N y){
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            adjMatrix[xIndex][yIndex] = true;
        }
    }
    void deleteEdge(N x, N y)
    {
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        adjMatrix[xIndex][yIndex] = false;
    }
    
    void dfs( N v ) {
        map<N, bool> visited;
        do_dfs(visited, v);
    }

    void do_dfs(map<N, bool> &visited, N v ) {
        cout << "Matrix DFS: Visiting node: " << v << std::endl;
        visited[v] = true;
        auto v_neighbors = neighbors(v);
        for (auto w: v_neighbors){
          if( visited.count(w) < 1 ){
            do_dfs(visited, w);
          }
        }
    }

    void bfs(N s) {  //https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
        map<N, bool> visited;

        list<N> queue;

        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty())
        {
            auto v = queue.front();
            queue.pop_front();

            cout << "Matrix BFS: Visiting node: " << v << std::endl;
            visited[v] = true;

            for (auto w: neighbors(v))
            {
                if (visited.count(w) < 1)
                {
                    visited[w] = true;
                    queue.push_back(w);
                }
            }
        }
    }

};
