#pragma once
#include "NodoPiloto.h"

class ListaPiloto
{
private:

	NodoPiloto* primero;
	NodoPiloto* actual;

public:

	ListaPiloto();
	~ListaPiloto();

	bool insertar(Piloto*);
	bool listaVacia();
	Piloto* buscar(string);

	void guardarPiloto(string);

	string toStringListaPiloto();
};

