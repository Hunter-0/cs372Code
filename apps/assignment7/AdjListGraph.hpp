#pragma once
#include "Graph.hpp"
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

template <class N>
class AdjListGraph: public Graph<N>  {
private:
  using Edges = list<pair<N, N>>;
  map<N, Edges > vertexMap;
public:
  // Default constuctor, create empty
  AdjListGraph() : Graph<N>() { };

  // Get the vertex map from the Graph we're copying
  AdjListGraph(const AdjListGraph& other) : Graph<N>()
    {
      vertexMap = other->vertexMap;
    }

  // Don't forget to overload the assignment operator
  AdjListGraph& operator= (const AdjListGraph &source)
    {
      vertexMap = source->vertexMap;
      return *this;
    }

  // Add the nodes in the list to graph
  AdjListGraph(vector<N> newNodes, vector<pair<N,N>> newEdges) :
    Graph<N>(newNodes, newEdges)
    {
      for (auto it = newNodes.begin();
           it < newNodes.end();
           ++it)
      {
        N node = *it;
        vertexMap[node].push_back(newEdges);
      }
    }


  // Clean up behind ourselves
  ~AdjListGraph() { }

  bool adjacent(N x, N y){
    Edges edges = vertexMap.at(x);
    pair<N,N> *searchEdge = new pair<N,N>(x,y);
    typename Edges::const_iterator begin = edges.begin();
    typename Edges::const_iterator end = edges.end();
    auto pos = std::find_if(begin,end,
                            [&](pair<N,N> const &b) {
                              bool match =  (b.first == searchEdge->first
                                              && b.second == searchEdge->second);
                              return match;
                            });
    bool match = false;
    if (pos != end) { match = true; }
    return (match);
  }

  vector<N> neighbors(N x) {
    vector<N> *nodes = new vector<N>();
    Edges edges = vertexMap.at(x);
    for (typename Edges :: const_iterator it = edges.begin(); it != edges.end(); it++) {
      pair<N,N> e = *it;
      if (e.first != x) {
        nodes->push_back(e.first);
      }
      if (e.second != x) {
        nodes->push_back(e.second);
      }
    }
    return *nodes;
  }

  void addNode(N node){
    Edges * newEdgeList = new Edges();
    vertexMap[node] = *newEdgeList;
  }

  void addEdge(N x, N y){
    pair<N,N> forwardEdge = make_pair(x,y);
    pair<N,N> backwardEdge = make_pair(y,x);
    vertexMap[x].push_back(forwardEdge);
    vertexMap[y].push_back(backwardEdge);

  }

  void deleteEdge(N x, N y){
    pair<N,N> forwardEdge = make_pair(x,y);
    pair<N,N> backwardEdge = make_pair(y,x);
    vertexMap[x].remove(forwardEdge);
    vertexMap[y].remove(backwardEdge);
  }

  void dfs( N v ) {
      map<N, bool> visited;
      do_dfs(visited, v);
  }

  void do_dfs(map<N, bool> &visited, N v ) {
      cout << "List DFS: Visiting node: " << v << std::endl;
      visited[v] = true;
      auto v_neighbors = neighbors(v);
      for (auto w: v_neighbors){
        if( visited.count(w) < 1 ){
          do_dfs(visited, w);
        }
      }
  }

  void bfs(N s) {
      map<N, bool> visited;

      list<N> queue;

      visited[s] = true;
      queue.push_back(s);

      while(!queue.empty())
      {
          auto v = queue.front();
          queue.pop_front();

          cout << "List BFS: Visiting node: " << v << std::endl;
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