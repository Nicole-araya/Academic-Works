#pragma once
#include"NodoSobrecargo.h"

class ListaSobrecargo
{
private:

	NodoSobrecargo* primero;
	NodoSobrecargo* actual;

public:
	ListaSobrecargo();
	~ListaSobrecargo();

	bool insertar(Sobrecargo*);
	bool listaVacia();

	Sobrecargo* buscar(string);

	void guardarSobrecargo(string);

	string toStringListaSobrecargo();
};

