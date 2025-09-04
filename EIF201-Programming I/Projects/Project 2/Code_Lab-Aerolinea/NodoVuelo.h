#pragma once
#include "Vuelo.h"
class NodoVuelo
{
private:

	Vuelo* info;
	NodoVuelo* sig;

public:

	NodoVuelo(Vuelo*, NodoVuelo*);
	~NodoVuelo();

	void setVuelo(Vuelo*);
	void setSiguiente(NodoVuelo*);
	Vuelo* getVuelo();
	NodoVuelo* getSiguiente();

	string toStringNodoVuelo();
};

