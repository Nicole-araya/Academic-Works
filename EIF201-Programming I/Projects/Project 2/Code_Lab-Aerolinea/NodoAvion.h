#pragma once
#include "Avion.h"
class NodoAvion
{
private:

	Avion* info;
	NodoAvion* sig;

public:

	NodoAvion(Avion*, NodoAvion*);
	~NodoAvion();

	void setAvion(Avion*);
	void setSiguiente(NodoAvion*);
	Avion* getAvion();
	NodoAvion* getSiguiente();

	string toStringNodoAvion();
};

