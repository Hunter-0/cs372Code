#include "AdjListGraph.hpp"
#include "AdjMatrixGraph.hpp"
#include <iostream>

int main(){
    AdjListGraph<int> *g = new AdjListGraph<int>();
    g->addNode(1);
    g->addNode(2);
    g->addNode(3);
    g->addNode(4);
    g->addNode(5);
    g->addNode(6);
    g->addNode(7);
    g->addNode(8);
    g->addNode(9);
    g->addNode(10);

    g->addEdge(1, 2);
    g->addEdge(1, 5);
    g->addEdge(1, 9);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(5, 6);
    g->addEdge(6, 7);
    g->addEdge(5, 8);
    g->addEdge(9, 10);

    g->dfs(1);
    g->bfs(1);

   AdjMatrixGraph<int>* m = new AdjMatrixGraph<int>();
    m->addNode(1);
    m->addNode(2);
    m->addNode(3);
    m->addNode(4);
    m->addNode(5);
    m->addNode(6);
    m->addNode(7);
    m->addNode(8);
    m->addNode(9);
    m->addNode(10);

    m->addEdge(1, 2);
    m->addEdge(1, 5);
    m->addEdge(1, 9);
    m->addEdge(2, 3);
    m->addEdge(3, 4);
    m->addEdge(5, 6);
    m->addEdge(6, 7);
    m->addEdge(5, 8);
    m->addEdge(9, 10);

    m->dfs(1);
    m->bfs(1);

}