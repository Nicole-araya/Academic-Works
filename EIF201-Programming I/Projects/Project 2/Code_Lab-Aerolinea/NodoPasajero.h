#pragma once
#include "Pasajero.h"

class NodoPasajero
{
private:

	Pasajero* info;
	NodoPasajero* sig;

public:

	NodoPasajero(Pasajero*,NodoPasajero*);
	~NodoPasajero();

	void setPasajero(Pasajero*);
	void setSiguiente(NodoPasajero*);
	Pasajero* getPasajero();
	NodoPasajero* getSiguiente();

	string toStringNodoPasajero();
};

