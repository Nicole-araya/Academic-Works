#include "NodoVuelo.h"

NodoVuelo::NodoVuelo(Vuelo* info, NodoVuelo* sig) {

	this->info = info;
	this->sig = sig;

}

NodoVuelo::~NodoVuelo() {
	delete info;
}

void NodoVuelo::setVuelo(Vuelo* info) {
	this->info = info;
}
void NodoVuelo::setSiguiente(NodoVuelo* sig) {
	this->sig = sig;
}
Vuelo* NodoVuelo::getVuelo() {

	return info;
}
NodoVuelo* NodoVuelo::getSiguiente() {
	return sig;
}

string NodoVuelo::toStringNodoVuelo() {
	stringstream s;

	s << info->MostrarVueloSimple();

	return s.str();
}