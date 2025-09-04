#include "Graph.h"

Graph::Graph(int num)
{
	numVertices = num;
	adjMatrix = new bool* [numVertices];

	for (int i = 0; i < numVertices; i++) {
		adjMatrix[i] = new bool[numVertices];
	}

	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			adjMatrix[i][j] = NULL;
		}
	}
}

Graph::Graph(const Graph& g2)
{

}

void Graph::addEdge(int i, int j)
{
	adjMatrix[i][j] = true;
}

void Graph::removeEdge(int i, int j)
{
	adjMatrix[i][j] = false;
}

bool Graph::isAdjacent(int v, int w)
{
	if (adjMatrix[v][w] == true || adjMatrix[w][v] == true) {
		return true;
	}
	return false;
}

string Graph::toString()
{
	stringstream s;
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			if (adjMatrix[i][j] ==true) {
				s << i << "," << j << endl;
			}
		}
	}
	return s.str();
}

Graph::~Graph()
{
	for (int i = 0; i < numVertices; i++) {
		delete adjMatrix[i];

	}
	delete[] adjMatrix;
}
