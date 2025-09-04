#pragma once
#include "Lista.h"
#include "Sort.h"
#include "DisjointSets.h"
#include "Vertice.h"

template<class T>
class Graph{
private:
	struct Trip {
		int weight;
		Vertice<T> first;
		Vertice<T> second;


		Trip(int f, int s, int W);
		Trip(Vertice<T> f, Vertice<T> s, int w);
		bool operator>(const Trip& B);
	};

	int V;
	Lista<Trip> edges;

public:
	
	Graph(int V);//V es tamaño; E -> idk
	void addEdge(int u, int v, int w);
	void addEdge(Vertice<T> u, Vertice<T> v, int w);
	int kruskalMST();
};

template<class T>
inline Graph<T>::Trip::Trip(int f, int s, int W){
	first = f;
	second = s;
	weight = W;
}

template<class T>
inline Graph<T>::Trip::Trip(Vertice<T> f, Vertice<T> s, int w){//con objetos
	first = f;
	second = s;
	weight = w;
}

template<class T>
inline bool Graph<T>::Trip::operator>(const Trip& B){
	return this->weight > B.weight;
}

template<class T>
inline Graph<T>::Graph(int V){
	this->V = V;
}

template<class T>
inline void Graph<T>::addEdge(int u, int v, int w){
	edges.agregarFinal(new Trip(u, v, w));
}

template<class T>
inline void Graph<T>::addEdge(Vertice<T> u, Vertice<T> v, int w){
	edges.agregarFinal(new Trip(u, v, w));
}

template<class T>
inline int Graph<T>::kruskalMST(){
	int mst_wt = 0;
	Lista<Trip> mst;
	Sort<Trip>::quickSort(edges);

	DisjointSets ds(V);
	typename Lista<Trip>::Iterador it= edges.root();

	for  (it; it.nd!= edges.end(); it++){
		int u = it.valor->first.getKey();
		int v = it.valor->second.getKey();

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v) {
			cout << u << " - " << v << endl;
			mst.agregarFinal(new Trip(*it.valor));

			mst_wt += it.valor->weight;
			ds.merge(set_u, set_v);
		}
	}

	typename Lista<Trip>::Iterador tt = mst.root();
	for (tt; tt.nd!=mst.end(); tt++){
		cout << (tt.valor->first.getInfo()) << " - " << (tt.valor->second.getInfo());
		cout << " Weight -> " << (tt.valor->weight)<<endl;//se puede retornar mst como lista ordenada de nodos
	}
	return mst_wt;
}