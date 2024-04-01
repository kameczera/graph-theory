#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

#include <vector>
#include <stack>

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int numVertices);

    void addEdge(int src, int dest);
    void printMatrix();
    void path();
    bool verifyConectivity(int v);
    void dfs(int start, int* visited);
    void dfs(int start, int lastNode, int i, int* visited, stack<int> stack);
    
};

#endif // GRAPH_H