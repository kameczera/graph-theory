#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph/Graph.h"
using namespace std;

int main() {
    Graph graph(5);

    // graph with cycles (6 in total)
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // graph with no cycles
    // graph.addEdge(0, 2);
    // graph.addEdge(2, 4);
    // graph.addEdge(4, 1);
    // graph.addEdge(0, 3);
    // Print adjacency matrix
    graph.printMatrix();
    graph.path();


    return 0;
}