#pragma once
#include "Edge.h"
#include <sstream>

template<class T>
class Graph{
private:
	Edge<T> vec[20];
	int tam;
	int cant;
public:
	Graph();
	void insertEdge(Edge<T> ed);
	bool eraseEdge(Edge<T> ed);
	bool adyacente(T ed1, T ed2);

	//adyacente;
	string toString();

};

template<class T>
inline Graph<T>::Graph()
{
	tam = 0;
	cant = 200;
}

template<class T>
inline void Graph<T>::insertEdge(Edge<T> ed){
	if (tam < cant) {
		vec[tam] = ed;
		tam++;
	}
}

template<class T>
inline bool Graph<T>::eraseEdge(Edge<T> ed){
	for (int i = 0; i < tam; i++){
		if (ed==vec[i]){
			for (int j = i; j < tam-i; j++){
				vec[j] = vec[j + 1];

			}
			tam--;
			return true;
		}

	}
	return false;
}

template<class T>
inline bool Graph<T>::adyacente(T v, T u){
	for (int i = 0; i < tam; i++){
		if (*vec[i].getFirst() == v && *vec[i].getSecond()==u) {
			return true;
		}
		else if (*vec[i].getFirst() == u && *vec[i].getSecond() == v) {
			return true;
		}

	}
	return false;
}

template<class T>
inline string Graph<T>::toString(){
	stringstream ss;
	for (int i = 0; i < tam; i++){
		ss << *vec[i].getFirst()<<", ";
		ss << *vec[i].getSecond()<<endl;

	}
	return ss.str();
}
