#pragma once
#include "Ruta.h"

class NodoRuta
{
private:

	Ruta* info;
	NodoRuta* sig;

public:

	NodoRuta(Ruta*, NodoRuta*);
	~NodoRuta();

	void setRuta(Ruta*);
	void setSiguiente(NodoRuta*);
	Ruta* getRuta();
	NodoRuta* getSiguiente();

	string toStringNodoRuta();
};

