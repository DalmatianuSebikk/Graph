//
// Created by sebas on 11/3/2021.
//

#ifndef GRAPHPROJECTFINAL_GRAPH_H
#define GRAPHPROJECTFINAL_GRAPH_H


#include <vector>

class Graph {
private:
#pragma region attributes

    int numberOfElements; // the number of nodes from the graph
    std::vector<int> adjacentList[100000]; // implementing the graph using an array of adjacentLists

#pragma endregion

#pragma region private functions that help at stuff
    void addEdgeOriented(int a, int b); // if we are working with an oriented graph
    void addEdgeUnoriented(int a, int b); // if we are working with an unoriented graph
#pragma endregion
public:
#pragma region public functions related to the class

    Graph(int numberOfElements);

    Graph();

    void readOriented(); // reading the data for an oriented graph
    void printGraph(); // output the content from the graph
    void readUnoriented(); // reading the data for an unoriented graph

    void dfsRec(int node); // recursive definition of the DFS for the given node.
    void dfsIter(int node); // iterative definitions of the DFS for the given node.
    int numberOfConnectedComponents(); // returns the number of connected components in the Graph
    void topologicalSort(); // topological sort using Kahn's Algorithm
    void bfs(int node); // BFS for the given node, outputs the distances;
    int checkHavelHakimi(std::vector<int>& nodeDegrees); // returns the value of the Havel Hakimi algorithm

#pragma endregion

};


#endif //GRAPHPROJECTFINAL_GRAPH_H
