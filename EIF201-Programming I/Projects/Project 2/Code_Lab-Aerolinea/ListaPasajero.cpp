#include "ListaPasajero.h"

ListaPasajero::ListaPasajero(){

	primero = NULL;
	actual = NULL;
}

ListaPasajero::~ListaPasajero() {
	while (primero != NULL) { 
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaPasajero::insertar(Pasajero* pasajero) {

	actual = primero;


	if (primero == NULL) {
		primero = new NodoPasajero(pasajero, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoPasajero(pasajero, NULL));
		return true;
	}

}

bool ListaPasajero::listaVacia() {

	if (primero == NULL) return true;

	return false;
}

Pasajero* ListaPasajero::buscar(string id) {  //VER SI ES UTIL ESTA OPCION

	actual = primero;

	while (actual != NULL) {

		if (actual->getPasajero()->getID() == id) {

			return actual->getPasajero();
		}
			actual = actual->getSiguiente();
	
	}
	return NULL;
}

string ListaPasajero::toStringListaPasajero() {

	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoPasajero();
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}