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
    int numberOfEdges;
    int diameterOfTree; // The diameter of the tree, used for InfoArena
    int lastNode;
    bool isOriented; // bool that checks if the graph is oriented / unoriented (oriented -> true, unoriented -> false)
    // todo: schimba std::vector
    std::vector<int> adjacentList[100000]; // implementing the graph using an array of adjacentLists


#pragma endregion

#pragma region private functions that help at building the graph
    void addEdgeOriented(int a, int b); // using this function at reading if we are working with an oriented graph
    void addEdgeUnoriented(int a, int b); // using this function at reading if we are working with an unoriented graph
    void eulerFunction(int node, std::vector<int> &cycles);
#pragma endregion

public:
    // todo: FUNCTII CARE RETURNEAZA!
#pragma region public functions related to the class

    Graph(int numberOfElements, int numberOfEdges, bool isOriented);
    Graph();

    // void checkTypeAndRead(); // check the type of the graph
    void readOriented(std::ifstream &file); // reading the data for an oriented graph
    void readUnoriented(std::ifstream &file); // reading the data for an unoriented graph
    void printGraph(); // output the content from the graph
    void dfsRec(int node); // recursive definition of the DFS for the given node.
    void dfsIter(int node); // iterative definitions of the DFS for the given node.
    void bfs(int node); // BFS for the given node, outputs the distances;

    int getDiameter(); // getter for the diameter
    int getLastNode(); // getter for the last node after the bfs

    int numberOfConnectedComponents(); // returns the number of connected components in the Graph
    void topologicalSort(); // topological sort using Kahn's Algorithm
    bool checkHavelHakimi(std::vector<int>& nodeDegrees); // returns the value of the Havel Hakimi algorithm
    std::vector<int> getEulerianCycle();

    void royFloydAlgorithm(int weightMatrix[100][100]); // for solving the royfloyd algorithm

#pragma endregion

};


#endif //GRAPHPROJECTFINAL_GRAPH_H
