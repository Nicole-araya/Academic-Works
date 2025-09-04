#include "NodoPasajero.h"

NodoPasajero::NodoPasajero(Pasajero* info, NodoPasajero* sig) {
	this->info = info;
	this->sig = sig;
}

NodoPasajero::~NodoPasajero() {
	delete info;
}

void NodoPasajero::setPasajero(Pasajero* info) {
	this->info = info;
}
void NodoPasajero::setSiguiente(NodoPasajero* sig) {
	this->sig = sig;
}
Pasajero* NodoPasajero::getPasajero() {
	return info;
}
NodoPasajero* NodoPasajero::getSiguiente() {
	return sig;
}

string NodoPasajero::toStringNodoPasajero() {
	stringstream s;

	s << info->toString();
	
	return s.str();
}