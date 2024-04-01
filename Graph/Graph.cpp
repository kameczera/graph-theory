#include "Graph.h"
#include <iostream>
#include <limits>
#include <stack>

using namespace std;

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
}

void Graph::addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; // For undirected graph
}

void Graph::printMatrix() {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

// This function do a dfs for each vertex.
void Graph::path(){
    for(int v = 0; v < numVertices; v++){
        int* visited = (int*) malloc(sizeof(int) * numVertices);
        for(int i = 0; i < numVertices; i++){
            visited[i] = 0;
        }
        stack<int> stack;
        dfs(v, v, v, visited, stack);
        cout << "\n";
        delete(visited);
    }
}


/*
    Depth First Search: This function will traverse the graph searching for the next non-visited node until all nodes are visited. 
    When this happen, it'll go back the stack searching for new paths

    Observation:
        -> lastNode exists just to not print sub-graphs with 2 vertex.
        -> The first to visit is the last to print (stack)
        -> This function will print the same cycle multiple times

    All the comments I wrote are couts to print the step-by-step of the algorithm
*/
void Graph::dfs(int start,int lastNode, int currentNode, int visited[], stack<int> s){
    s.push(currentNode);
    int visitedCopy[numVertices];
    for(int i = 0; i < numVertices; i++){
        visitedCopy[i] = visited[i];
        // cout << visitedCopy[i] << " ";
    }
    // cout << "\n";
    for(int j = 0; j < numVertices; j++){
        if(lastNode != j){
            if(visited[j] == 0 && adjMatrix[currentNode][j] == 1) {
                if(start != j) {
                    visitedCopy[j] = 1;
                    // cout << "j: " << j << " & currentNode: " << currentNode << " & lastNode: " << lastNode << " -> ";
                    dfs(start, currentNode, j, visitedCopy, s);
                    visitedCopy[j] = 0;
                }else if(start == j){
                    stack<int> temp = s;
                    cout << "find cycle -> ";
                    while(!temp.empty()) {
                        cout << temp.top();
                        temp.pop();
                    }
                    cout << "\n";
                }
            }
        }
    }
}