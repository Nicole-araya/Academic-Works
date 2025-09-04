#include"Nodo.h"

Nodo::Nodo(Producto* pro, Nodo* si) {
	producto = pro;
	sig = si;   
}
Nodo::~Nodo() {
	if (producto) delete producto;
}
Producto* Nodo::getProducto() {
	return producto;
}
Nodo* Nodo::getSiguiente() {
	return sig;
}
void Nodo::setProducto(Producto* pro) {
	producto = pro;
}
void Nodo::setSiguiente(Nodo* si) {
	sig = si;
}

string Nodo::toString() {

	stringstream s;

	s << producto->toString();

	return s.str();
}