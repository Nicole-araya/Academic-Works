#include "Graph.h"

int main() {

	Graph* g = new Graph(5);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(4, 2);
	g->addEdge(3, 1);
	cout << g->toString() << endl;

	g->removeEdge(4, 2);
	cout << g->toString() << endl;

	if (g->isAdjacent(1, 2) == true) {
		cout << "Es adyacente\n";
	}
	else {
		cout << "NO es adyacente\n";
	}

	if (g->isAdjacent(4, 2) == true) {
		cout << "Es adyacente\n";
	}
	else {
		cout << "NO es adyacente\n";
	}

	return 0;
}