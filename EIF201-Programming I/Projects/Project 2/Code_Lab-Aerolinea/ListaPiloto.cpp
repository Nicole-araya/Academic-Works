#include "ListaPiloto.h"
ListaPiloto::ListaPiloto() {
	primero = NULL;
	actual = NULL;
}
ListaPiloto::~ListaPiloto() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaPiloto::insertar(Piloto* piloto) {
	actual = primero;


	if (primero == NULL) {
		primero = new NodoPiloto(piloto, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoPiloto(piloto, NULL));
		return true;
	}
}
bool ListaPiloto::listaVacia() {
	if (primero == NULL) return true;

	return false;
}
Piloto* ListaPiloto::buscar(string id) {
	actual = primero;

	while (actual != NULL) {

		if (actual->getPiloto()->getID() == id) {

			return actual->getPiloto();
		}
		actual = actual->getSiguiente();

	}
	return NULL;
}

void ListaPiloto::guardarPiloto(string nom)
{
	ofstream salida(nom);

	actual = primero;
	while (actual != NULL) {

		actual->getPiloto()->guardar(salida);

		actual = actual->getSiguiente();
	}
	salida.close();
}

string ListaPiloto::toStringListaPiloto() {
	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoPiloto();
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}