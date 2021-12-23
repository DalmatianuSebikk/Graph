//
// Created by sebas on 11/3/2021.
//

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include "Graph.h"
#include <fstream>

#pragma region constructors
Graph::Graph(int numberOfElements, int numberOfEdges, bool isOriented) : numberOfElements(numberOfElements), numberOfEdges(numberOfEdges), isOriented(isOriented) {}
Graph::Graph() {
    numberOfElements = 0;
    numberOfEdges = 0;
    isOriented = false;
}

#pragma endregion

#pragma region functions that help at reading and writing

int Graph::getDiameter() {
    return diameterOfTree;
}
int Graph::getLastNode() {
    return lastNode;
}

void Graph::addEdgeOriented(int a, int b) {
    if(a != b) {
        adjacentList[a].push_back(b);
    }
}

void Graph::addEdgeUnoriented(int a, int b) {
    if(a == b) {
        adjacentList[a].push_back(b); // solving duplicates
    }
    else {
        adjacentList[a].push_back(b);
        adjacentList[b].push_back(a);
    }

}

void Graph::readOriented(std::ifstream &file) {
    int nodes, edges;
    file >> nodes >> edges;

    int x, y; // for reading the edges
    while(edges != 0) {
        file >> x >> y;
        addEdgeOriented(x, y);
        edges--;
    }
}

void Graph::readUnoriented(std::ifstream &file) {
    int edges = numberOfElements - 1;
    int x, y; // for reading the edges
    while (edges != 0) {
        file >> x >> y;
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

void Graph::royFloydAlgorithm(int weightMatrix[100][100]) {
    for(int k = 0; k < numberOfElements; k++) {
        for(int i = 0; i < numberOfElements; i++) {
            for(int j = 0; j < numberOfElements; j++) {
                if(
                        i != j &&
                        weightMatrix[i][k] &&
                        weightMatrix[k][j] &&
                        (weightMatrix[i][j] > weightMatrix[i][k] + weightMatrix[k][j] || !weightMatrix[i][j])

                        ) {
                    weightMatrix[i][j] = weightMatrix[i][k] + weightMatrix[k][j];
                }
                // if(
                //         weightMatrix[i][k] &&
                //         weightMatrix[k][j] &&
                //         (weightMatrix[i][j] > weightMatrix[i][k] + weightMatrix[k][j] || !weightMatrix[k][j] && i != j) -> greseala i!=j in par.
                //     )
                //     {
                //         weightMatrix[i][j] = weightMatrix[i][k] + weightMatrix[k][j];
                //     }
            }
        }
    }
}

// DFS -> ITERATIVE AND RECURSIVE
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

// INFOARENA: BFS
void Graph::bfs(int node) {

    int visitedNodes[100000] = {0}, nodeDegree[100000] = {0};
    int distance[100000] = {0};

    std::queue<int> nodeQueue;
    visitedNodes[node] = 1;
    nodeQueue.push(node);

    // Modify the BFS for InfoArena
    // you need a counter array so that you can measure the distance
    int counter[100000] = {0};

    counter[node] = 1; // set the starting node's counter to 1


    while(!nodeQueue.empty()) {
        // pop the front
        int front = nodeQueue.front();
        // find the neighbours of the current node
        for(auto theOtherNodes : adjacentList[front]) {
            // theOtherNodes = nod[el][i]
            // contor = counter;
            if(visitedNodes[theOtherNodes] == 0) {
                // mark them and then increase the distance between the nodes
                nodeQueue.push(theOtherNodes);
                visitedNodes[theOtherNodes] = 1;

                // modification for InfoArena
                counter[theOtherNodes] = counter[front] + 1; // increase the counter for the visited node.

                diameterOfTree = counter[theOtherNodes];
                lastNode = theOtherNodes;
            }
        }
        nodeQueue.pop();
    }
    //output the distances
    // for(int i = 0; i < numberOfElements; i++) {
    //     if(visitedNodes[i] != 0) {
    //         std::cout << distance[i] << " ";
    //     }
    //     else {
    //         std::cout << -1 << " ";
    //     }
    // }
}

//INFOARENA -> Connected components
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

//INFOARENA -> Topological Sort (with BFS, tried with DFS and it doesn t work propely)
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


// Check the Havel Hakimi for a given array
bool Graph::checkHavelHakimi(std::vector<int>& nodeDegrees) {
    // used the STL vector because it's easier than working with arrays.

    while(true) {
        // if the nodeDegrees vector is empty or it only contains zeroes, then it's valid
        if(nodeDegrees.empty() || std::all_of(nodeDegrees.begin(), nodeDegrees.end(), [](int i) {return i == 0;})) {
            return true;
        }

        // sort the vector
        std::sort(nodeDegrees.begin(), nodeDegrees.end());

        std::cout << "\n";
        int lastElement = nodeDegrees[nodeDegrees.size() - 1];
        if(lastElement > nodeDegrees.size() - 1) {
            return false;
        }

        nodeDegrees.erase(nodeDegrees.begin() + nodeDegrees.size() - 1);

        for(int i =  nodeDegrees.size() - 1; i > nodeDegrees.size() - 1 - lastElement ; i--) {
            if(nodeDegrees[i] > 0) {
                nodeDegrees[i]--;
            }
            else {
                return false;
            }
        }
    }
}

void Graph::eulerFunction(int node, std::vector<int> &cycles) {
    // verifying the parity for every node
    for (int i=0;i<=numberOfElements; i++) {
        int co=0;
        for(auto& neighbour : adjacentList[i]){
            if(neighbour!=i)
                co++;
            else
                co+=2;
        }
        if(co%2==1)
            return;
    }

    std::stack<int> nodeStack;
    // cycles.push_back(node);
    nodeStack.push(node);

    while (!nodeStack.empty()) {

        int currentNode = nodeStack.top();
        // std::vector<int> currentCycles = std::get<1>(currentTuple);
        // nodeStack.pop();

        if (!adjacentList[currentNode].empty()) {

            int neighbour = adjacentList[currentNode].back();
            adjacentList[currentNode].pop_back();

         if (currentNode != neighbour) {

            auto find = std::find(adjacentList[neighbour].begin(), adjacentList[neighbour].end(), currentNode);
            if (find != adjacentList[neighbour].end()) {
                *find = adjacentList[neighbour].back();
                adjacentList[neighbour].pop_back();
            }
         }

            nodeStack.push(neighbour);
        } else {
            nodeStack.pop();
            cycles.push_back(currentNode);
        }
//        cycles.push_back(currentNode);
    }
}

std::vector<int> Graph::getEulerianCycle() {
    std::vector<int> result;
    // std::stack<std::tuple<int, std::vector<int>>> nodeStack;
    result.reserve(numberOfElements);

    eulerFunction(1, result);
    if(result.size()!=numberOfEdges+1)
        return {};

    for(int i = 0; i < numberOfElements; i++) {

        if(!adjacentList[i].empty()){
            return {};
        }
    }
    for(auto& i: result) {
        i++;
    }

    return result;

}



#pragma endregion


