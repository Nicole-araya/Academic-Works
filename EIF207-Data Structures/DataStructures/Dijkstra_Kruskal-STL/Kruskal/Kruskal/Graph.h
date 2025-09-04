#pragma once
#include <utility>
#include<vector>
#include<algorithm>
#include"DisjointSets.h"
#include<iostream>

using namespace std;

typedef pair<int, int> iPair;
class Graph{
private:
	int V, E;
	vector<pair<int, iPair>> edges;

public:
	Graph(int V, int E);
	void addEdge(int u, int v, int w);
	int kruskalMST();
};

