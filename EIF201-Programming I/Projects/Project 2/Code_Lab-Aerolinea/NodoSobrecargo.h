#pragma once
#include "Sobrecargo.h"

class NodoSobrecargo
{
private:

	Sobrecargo* info;
	NodoSobrecargo* sig;

public:
	NodoSobrecargo(Sobrecargo*, NodoSobrecargo*);
	~NodoSobrecargo();

	void setSobrecargo(Sobrecargo*);
	void setSiguiente(NodoSobrecargo*);
	Sobrecargo* getSobrecargo();
	NodoSobrecargo* getSiguiente();

	string toStringNodoSobrecargo();

};

