#pragma once
#include<list>
#include <utility>
#include <set>
#include<vector>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

template<class T>
class Graph{
	int V;
	list<pair<T, int>>* adj;
public:
	Graph(int V);
	void addEdge(T u, T v, int w);
	void shortestPath(int s);
	void printVector(vector<int>);
};


template<class T>
Graph<T>::Graph(int V) {
	this->V = V;
	adj = new list<pair<T, int>>[V];
}

template<class T>
void Graph<T>::addEdge(T u, T v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

template<class T>
void Graph<T>::shortestPath(int src) {
	set<pair<T, int>> setds;
	vector<int> dist(V, INF);
	setds.insert(make_pair(0, src));
	dist[src] = 0;
	while (!setds.empty()) {
		pair<T, int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int u = tmp.second;
		list<pair<T, int>>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;
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
template<class T>
void Graph<T>::printVector(vector<int> dist) {
	cout << "Vertex distance from sourde\n";
	for (int i = 0; i < V; i++) {
		cout << i << "\t\t" << dist[i] << endl;

	}
}