#pragma once
#include "Lista.h"
#define INF 0x3f3f3f3f
using namespace std;

class Graph {

	struct Pair {
		int first;
		int second;

		Pair(int f, int s);
		bool operator==(const Pair& B);
	};

	struct Set
	{
		Lista<Pair>* set;
		Set();
		Lista<Pair>* getListaSet();
		void insertar(Pair* p);
	};

	struct Vector {
		int *vector;
		int tam, can;
		Vector(int V);
		void insertarVec(int x);
	};

	int V;
	Lista<Pair>* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
	void printVector(int vec[]);
};

