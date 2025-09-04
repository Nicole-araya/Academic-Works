#pragma once
#include <utility>
#include<vector>
#include<algorithm>
#include"DisjointSets.h"
#include<list>
#include<iostream>

using namespace std;
template<class T, class K>

class GraphK{
	typedef pair<T, T> iPair;
private:
	int V;
	vector<pair<K, iPair>> edges;

public:
	GraphK(int V);
	void addEdge(T u, T v, K w);
	K kruskalMST(list< pair<K, iPair>>& lista);
	void imprimir();
};


template<class T, class K>
GraphK<T, K>::GraphK(int V) {
	this->V = V;
}

template<class T, class K>
void GraphK<T, K>::addEdge(T u, T v, K w) {
	edges.push_back({ w,{u,v} });
}

template<class T, class K>
inline K GraphK<T, K>::kruskalMST(list< pair<K, iPair>>& lista)
{
	K mst_wt = 0;
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	typename vector<pair<K, iPair>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++) {
		T u = it->second.first;
		T v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v) {
			lista.push_back({ it->first,{u,v} });
			mst_wt += it->first;
			ds.merge(set_u, set_v);
		}

	}
	return mst_wt;
	
}

template<class T, class K>
void GraphK<T, K>::imprimir() {
	list< pair<K, iPair>> lista;
	kruskalMST(lista);
	typename list<pair<K, iPair>>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++) {
		cout << it->second.first << " - " << it->second.second << ", peso: " << it->first << endl;
	}
}