#include "NodoSobrecargo.h"

NodoSobrecargo::NodoSobrecargo(Sobrecargo* info, NodoSobrecargo* sig) {

	this->info = info;
	this->sig = sig;

}
NodoSobrecargo::~NodoSobrecargo() {
	delete info;
}

void NodoSobrecargo::setSobrecargo(Sobrecargo* info) {
	this->info = info;
}
void NodoSobrecargo::setSiguiente(NodoSobrecargo* sig) {
	this->sig = sig;
}
Sobrecargo* NodoSobrecargo::getSobrecargo() {
	return info;
}
NodoSobrecargo* NodoSobrecargo::getSiguiente() {
	return sig;
}

string NodoSobrecargo::toStringNodoSobrecargo() {
	stringstream s;

	s << info->toString();

	return s.str();
}