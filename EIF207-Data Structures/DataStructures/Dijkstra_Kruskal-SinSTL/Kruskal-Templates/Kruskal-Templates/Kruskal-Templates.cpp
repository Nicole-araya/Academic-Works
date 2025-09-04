#include <iostream>
#include "Graph.h"

int main(){

    Graph<int> gg(10);
    
    gg.addEdge(2, 3, 8);
    gg.addEdge(2, 8, 3);
    gg.addEdge(3, 5, 7);
    gg.addEdge(5, 1, 8);
    gg.addEdge(9, 5, 3);
    gg.addEdge(5, 6, 2);
    cout << gg.kruskalMST() << endl;

    Vertice<string> a("a", 1);
    Vertice<string> b("b", 2);
    Vertice<string> c("c", 3);
    Vertice<string> d("d", 4);
    Vertice<string> e("e", 5);
    Vertice<string> f("f", 6);
    Vertice<string> g("g", 7);
    Vertice<string> h("h", 8);

    Graph<string> p(9);
    p.addEdge(a, b, 3);
    p.addEdge(a, c, 1);
    p.addEdge(b, d, 1);
    p.addEdge(b, g, 5);
    p.addEdge(c, d, 2);
    p.addEdge(c, f, 5);
    p.addEdge(d, f, 2);
    p.addEdge(d, e, 4);
    p.addEdge(e, g, 2);
    p.addEdge(e, h, 1);
    p.addEdge(h, f, 3);

    cout << p.kruskalMST() << endl;
}