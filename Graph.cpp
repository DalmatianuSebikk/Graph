//
// Created by sebas on 11/3/2021.
//

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include "Graph.h"

#pragma region constructors
Graph::Graph(int numberOfElements) : numberOfElements(numberOfElements) {}

Graph::Graph() {}
#pragma endregion

#pragma region functions that help at reading and writing
void Graph::addEdgeOriented(int a, int b) {
    if(a != b) {
        adjacentList[a].push_back(b);
    }
}

void Graph::addEdgeUnoriented(int a, int b) {
    adjacentList[a].push_back(b);
    adjacentList[b].push_back(a);
}

void Graph::readOriented() {
    int nodes, edges;
    std::cin >> nodes >> edges;

    int x, y; // for reading the edges
    while(edges != 0) {
        std::cin >> x >> y;
        addEdgeOriented(x, y);
        edges--;
    }
}

void Graph::readUnoriented() {
    int nodes, edges;
    std::cin >> nodes >> edges;

    int x, y; // for reading the edges
    while(edges != 0) {
        std::cin >> x >> y;
        addEdgeUnoriented(x, y);
        edges--;
    }
}

void Graph::printGraph() {
    for(int node = 1; node <= numberOfElements; node++) {
        std::cout << "Nodul " << node << " are lista:";
        for(auto x : adjacentList[node]) {
            std::cout << "->" << x;
        }
        std::cout << "\n";
    }
}

#pragma endregion

#pragma region graph algorithms
void Graph::dfsRec(int node) {

    int visitedNodes[100000] = {0};

    if(visitedNodes[node] == 1){
        return;
    }
    visitedNodes[node] = 1;
    std::cout << node << " ";
    for(int adjacentNode : adjacentList[node]) {
        dfsRec(adjacentNode); // we are using the app's stack to traverse the graph
    }
}

void Graph::dfsIter(int node) {

    int visitedNodes[100000] = {0};

    std::stack<int> nodeStack;
    // 1. push the node
    nodeStack.push(node);
    visitedNodes[node] = 1;
    // std::cout << node << " ";

    // 2. Iterate through the adjacentList
    while(!nodeStack.empty()){
        // verify the top and then pop it.
        int top = nodeStack.top();
        if(visitedNodes[top] == 0) {
            // std::cout << top << " ";
            visitedNodes[top] = 1;
        }
        nodeStack.pop();

        for(int theOtherNodes : adjacentList[top]) {
            if(visitedNodes[theOtherNodes] == 0) {
                nodeStack.push(theOtherNodes);
            }
        }
    }
}

int Graph::numberOfConnectedComponents() {

    int visitedNodes[100000] = {0};

    int counter = 0;
    // traverse the nodes, if you find anything that is not visited, then increase the counter and do a DFS.
    for(int i = 0; i < numberOfElements; i++) {
        if(visitedNodes[i] == 0) {
            counter++;
            // calling the iterative version
            dfsIter(i);
        }
    }
    return counter;
}

void Graph::topologicalSort() {
    int visitedNodes[100000] = {0}, nodeDegree[100000] = {0};

    // create a queue
    std::queue<int> nodeQueue;
    std::vector<int> result;

    // calculate the degree of every node
    for(int i = 0; i < numberOfElements; i++) {
        for(int j : adjacentList[i]) {
            nodeDegree[j] += 1; // increasing the IN degree
        }
    }

    // enqueue all the nodes with degree = 0;

    for(int i = 0; i < numberOfElements; i++) {
        if(nodeDegree[i] == 0) {
            nodeQueue.push(i);
        }
    }

    while(!nodeQueue.empty()) {
        // dequeue the front element and push it into the result
        int front = nodeQueue.front();
        nodeQueue.pop();

        result.push_back(front);

        for(int newNode : adjacentList[front]) {
            // decrease the degree of the neighbours of the currently dequed element
            nodeDegree[newNode]--;
            // if the degree is zero, then enqueue it
            if(nodeDegree[newNode] == 0) {
                // enqueue all the nodes with degree == 0
                nodeQueue.push(newNode);
            }
        }
    }

    for(int i : result) {
        std::cout << i + 1 << " "; // output the vector
    }
}

void Graph::bfs(int node) {

    int visitedNodes[100000] = {0}, nodeDegree[100000] = {0};
    int distance[100000] = {0};

    std::queue<int> nodeQueue;
    visitedNodes[node] = 1;
    nodeQueue.push(node);

    while(!nodeQueue.empty()) {
        // pop the front
        int front = nodeQueue.front();
        nodeQueue.pop();

        // find the neighbours of the current node
        for(auto theOtherNodes : adjacentList[front]) {
            if(visitedNodes[theOtherNodes] == 0) {
                // mark them and then increase the distance between the nodes
                visitedNodes[theOtherNodes] = 1;
                nodeQueue.push(theOtherNodes);
                distance[theOtherNodes] = distance[front] + 1;
            }
        }
    }
    //output the distances
    for(int i = 0; i < numberOfElements; i++) {
        if(visitedNodes[i] != 0) {
            std::cout << distance[i] << " ";
        }
        else {
            std::cout << -1 << " ";
        }
    }
}

int Graph::checkHavelHakimi(std::vector<int>& nodeDegrees) {
    // used the STL vector because it's easier than working with arrays here.


    while(1) {
        // if the nodeDegrees vector is empty or it only contains zeroes, then it's valid
        if(nodeDegrees.empty() || std::all_of(nodeDegrees.begin(), nodeDegrees.end(), [](int i) {return i == 0;})) {
            return 1;
        }

        // sort the vector
        std::sort(nodeDegrees.begin(), nodeDegrees.end());

        for(int i : nodeDegrees) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        int lastElement = nodeDegrees[nodeDegrees.size() - 1];
        if(lastElement > nodeDegrees.size() - 1) {
            return 0;
        }

        nodeDegrees.erase(nodeDegrees.begin() + nodeDegrees.size() - 1);

        for(int i =  nodeDegrees.size() - 1; i > nodeDegrees.size() - 1 - lastElement ; i--) {
            if(nodeDegrees[i] > 0) {
                nodeDegrees[i]--;
            }
            else {
                return 0;
            }
        }
    }
}




#pragma endregion


