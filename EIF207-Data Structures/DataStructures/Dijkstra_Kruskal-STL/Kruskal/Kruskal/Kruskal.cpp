#include <iostream>
#include "Graph.h"
int main(){
    Graph idk(7,6);

    idk.addEdge(1, 4, 13);
    idk.addEdge(4,6,2);
    idk.addEdge(36,4,9);
    idk.addEdge(4,3,1);
    idk.addEdge(3,2,5);

    idk.kruskalMST();

//ni idea de que es esto
}

