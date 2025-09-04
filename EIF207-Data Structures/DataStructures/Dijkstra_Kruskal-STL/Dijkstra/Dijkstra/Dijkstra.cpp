#include <iostream>
#include "Graph.h"
int main(){
    int v = 9;
    Graph g(v);
    g.addEdge(0, 1, 4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.shortestPath(0);
    //g.printVector();


    std::cout << "Hello World!\n";
}

