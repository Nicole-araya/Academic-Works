#include "Grafo.h"



Graph::Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

bool Graph::Pair::operator==(const Pair& B)
{
	if (first != B.first && second != B.second) {
		return false;
	}
	else return true;
	
}
Graph::Set::Set(){
	set = new Lista<Pair>();
}

Lista<Graph::Pair>* Graph::Set::getListaSet()
{
	return set;
}

void Graph::Set::insertar(Pair* p)
{
	bool res = set->buscarIni(p);
	if (!res) set->agregarFinal(p);
}

Graph::Vector::Vector(int V)
{
	can = 0;
	tam = V;
	vector = new int[V];
	for (int i = 0; i < tam; i++) {
		vector[i] = INF;
	}
}

void Graph::Vector::insertarVec(int x)
{
	if (can < tam) {
		vector[can++] = x;
	}
}


Graph::Graph(int V)
{
	this->V = V;
	adj = new Lista<Pair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].agregarFinal(new Pair(v,w));
	adj[v].agregarFinal(new Pair(u, w));
}

void Graph::shortestPath(int s)
{
	Set setds;
	Vector vec(V);
	setds.insertar(new Pair(0, s));
	vec.vector[s] = 0;

	while (!setds.getListaSet()->estaVacia()) {

		Pair temp = *(setds.getListaSet()->begin()->Cursor());
		setds.getListaSet()->borrarIni();
		int u = temp.second;
		Iterador<Pair>* itor; 
		 

		for (itor = adj[u].begin(); itor->getCursor() != NULL; itor->next()) {
			int v = itor->Cursor()->first;
			int weight = itor->Cursor()->second;

			if (vec.vector[v] > vec.vector[u] + weight) {
				if (vec.vector[v] != INF) {

					Nodo<Pair>* nodo = setds.getListaSet()->buscarNodo(new Pair(vec.vector[v],v));
					setds.getListaSet()->borrar(nodo);
				}
				vec.vector[v] = vec.vector[u] + weight;
				setds.insertar(new Pair(vec.vector[v], v));
			}

		}
	}
	this->printVector(vec.vector);
}

void Graph::printVector(int vec[])
{
	cout << "Vertex distance from sourde\n";
	for (int i = 0; i < V; i++) {
		if (vec[i] != INF)        //si lo quito me muestra todo el tamannio (pinche esteban sapo)
		cout << i << "\t\t" << vec[i] << endl;
		
	}
}

