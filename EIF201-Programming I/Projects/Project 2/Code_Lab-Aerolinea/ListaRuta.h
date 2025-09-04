#pragma once
#include "NodoRuta.h"
class ListaRuta
{
private:

	NodoRuta* primero;
	NodoRuta* actual;

public:

	ListaRuta();
	~ListaRuta();

	bool insertar(Ruta*);
	bool listaVacia();

	Ruta* buscar(string);

	void guardarRuta(string);

	string toStringListaRuta();
};

