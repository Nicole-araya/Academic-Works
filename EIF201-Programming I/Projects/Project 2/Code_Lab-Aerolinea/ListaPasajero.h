#pragma once
#include "NodoPasajero.h"

class ListaPasajero
{
private:

	NodoPasajero* primero;
	NodoPasajero* actual;

public:

	ListaPasajero();
	~ListaPasajero();

	bool insertar(Pasajero*);
	bool listaVacia();

	Pasajero* buscar(string);

	string toStringListaPasajero();
};

