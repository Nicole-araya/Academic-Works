#include "NodoRuta.h"

NodoRuta::NodoRuta(Ruta* info, NodoRuta* sig) {

	this->info = info;
	this->sig = sig;

}

NodoRuta::~NodoRuta() {
	delete info;
}

void NodoRuta::setRuta(Ruta* info) {
	this->info = info;
}
void NodoRuta::setSiguiente(NodoRuta* sig) {
	this->sig = sig;
}
Ruta* NodoRuta::getRuta() {
	return info;
}
NodoRuta* NodoRuta::getSiguiente() {
	return sig;
}

string NodoRuta::toStringNodoRuta() {
	stringstream s;

	s << info->toStringRuta();

	return s.str();
}