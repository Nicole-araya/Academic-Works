#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Graph {

private:
	bool** adjMatrix;
	int numVertices;

public:
	Graph(int num = 1);
	Graph(const Graph& g2);
	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	bool isAdjacent(int v, int w);
	string toString();
	~Graph();


};
