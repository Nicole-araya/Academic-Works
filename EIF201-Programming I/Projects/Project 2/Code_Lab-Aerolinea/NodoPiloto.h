#pragma once
#include "Piloto.h"
class NodoPiloto
{
private:

	Piloto* info;
	NodoPiloto* sig;

public:

	NodoPiloto(Piloto*, NodoPiloto*);
	~NodoPiloto();

	void setVuelo(Piloto*);
	void setSiguiente(NodoPiloto*);
	Piloto* getPiloto();
	NodoPiloto* getSiguiente();

	string toStringNodoPiloto();
};

