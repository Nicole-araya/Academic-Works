#include "Graph.h"

Graph::Graph(int V, int E){
	this->V = V;
	this->E = E;
}

void Graph::addEdge(int u, int v, int w){
	edges.push_back({ w,{u,v} });
}

int Graph::kruskalMST(){
	int mst_wt = 0;
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	vector<pair<int, iPair>>::iterator it;
	for (it = edges.begin(); it!=edges.end(); it++)	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u!=set_v){
			cout << u << " - " << v << endl;
			mst_wt += it->first;
			ds.merge(set_u, set_v);
		}

	}
	return mst_wt;
}
