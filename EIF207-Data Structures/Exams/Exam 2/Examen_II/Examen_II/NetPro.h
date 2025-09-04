#pragma once
#include "Ruta.h"
#include "Lista.h"
#include "Archivo.h"
#include "Graphk.h"
#include "Graph.h"
#include "Excepcion.h"
const int TAM = 91;
const string NOM = "Grafo.txt";
using namespace std;
class NetPro
{
private:
	Lista<Ruta>* lista;
	Graph<char, double>* grapDijk;
	GraphK<char, double>* grapKrus;
public:
	NetPro();
	~NetPro();
	void menu();
};

