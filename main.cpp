#include <iostream>
#include "Graph.h"
int main() {

    Graph *graph = new Graph();
    std::vector<int> hakimiTest = {1, 1, 2, 3};
    int test = graph->checkHavelHakimi(hakimiTest);
    std::cout << test << " ";
    return 0;
}
