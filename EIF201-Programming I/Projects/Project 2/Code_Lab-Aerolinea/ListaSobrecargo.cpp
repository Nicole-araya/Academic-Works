#include "ListaSobrecargo.h"

ListaSobrecargo::ListaSobrecargo() {
	primero = NULL;
	actual = NULL;
}
ListaSobrecargo::~ListaSobrecargo() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaSobrecargo::insertar(Sobrecargo* sobrecargo) {
	actual = primero;


	if (primero == NULL) {
		primero = new NodoSobrecargo(sobrecargo, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoSobrecargo(sobrecargo, NULL));
		return true;
	}

	return false;
}

bool ListaSobrecargo::listaVacia() {
	if (primero == NULL) return true;

	return false;
}

Sobrecargo* ListaSobrecargo::buscar(string id) {
	actual = primero;

	while (actual != NULL) {

		if (actual->getSobrecargo()->getID() == id) {

			return actual->getSobrecargo();
		}
		actual = actual->getSiguiente();

	}
	return NULL;
}

void ListaSobrecargo::guardarSobrecargo(string nom)
{
	ofstream salida(nom);

	actual = primero;
	while (actual != NULL) {

		actual->getSobrecargo()->guardar(salida);

		actual = actual->getSiguiente();
	}
	salida.close();
}

string ListaSobrecargo::toStringListaSobrecargo() {
	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoSobrecargo();
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}