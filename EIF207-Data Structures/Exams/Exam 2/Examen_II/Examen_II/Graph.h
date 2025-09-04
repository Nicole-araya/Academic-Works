#pragma once
#include<list>
#include <utility>
#include <set>
#include<vector>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

template<class T,class K>
class Graph{
	int V;
	list<pair<T, K>>* adj;
public:
	Graph(int V);
	void addEdge(T u, T v, K w);
	void shortestPath(int s);
	void printVector(vector<K>);
};


template<class T, class K>
Graph<T,K>::Graph(int V) {
	this->V = V;
	adj = new list<pair<T, K>>[V];
}


template<class T, class K>
void Graph<T,K>::addEdge(T u, T v, K w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

template<class T, class K>
void Graph<T,K>::shortestPath(int src) {
	set<pair<T, K>> setds;
	vector<K> dist(V, INF);
	setds.insert(make_pair(65, src));
	dist[src] = 0;
	while (!setds.empty()) {
		pair<T, K> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int u = tmp.second; 
		typename list<pair<T, K>>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			K weight = (*i).second;
			if (dist[v] > dist[u] + weight) {
				if (dist[v] != INF) {
					setds.erase(setds.find(make_pair(dist[v], v)));
				}
				
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}		
		}
	}
	this->printVector(dist);
}

template<class T, class K>
void Graph<T,K>::printVector(vector<K> dist) {
	
	for (int k = 0; k < V; k++) {

		if (dist[k] != INF) {
			cout << char(k) << "\t\t" << dist[k] << endl;
		}

	}
}