#include <iostream>
#include "Grafo.h"

int main() {
    int v = 9;
   /* Graph g(v);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 7, 11);
    g.addEdge(2, 5, 6);
    g.shortestPath(0);*/


    Graph g(v);
    g.addEdge(1,2,3);
    g.addEdge(1,5,7);
    g.addEdge(1,3,2);
    g.addEdge(2,3,4);
    g.addEdge(3, 7,2);
    g.shortestPath(1);
}