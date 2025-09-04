#include "NodoPiloto.h"

NodoPiloto::NodoPiloto(Piloto* info, NodoPiloto* sig) {
	this->info = info;
	this->sig = sig;
}
NodoPiloto::~NodoPiloto() {
	delete info;
}

void NodoPiloto::setVuelo(Piloto* info) {
	this->info = info;
}
void NodoPiloto::setSiguiente(NodoPiloto* sig) {
	this->sig = sig;
}
Piloto* NodoPiloto::getPiloto() {
	return info;
}
NodoPiloto* NodoPiloto::getSiguiente() {
	return sig;
}

string NodoPiloto::toStringNodoPiloto() {
	stringstream s;

	s << info->toStringPiloto();

	return s.str();
}