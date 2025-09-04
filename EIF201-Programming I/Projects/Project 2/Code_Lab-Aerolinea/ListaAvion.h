#pragma once
#include "NodoAvion.h"
class ListaAvion
{
private:

	NodoAvion* primero;
	NodoAvion* actual;

public:

	ListaAvion();
	~ListaAvion();

	bool insertar(Avion*);
	bool listaVacia();

	Avion* buscar(string);

	void guardarAvion(string );

	string toStringListaAvion();

};

