#include "ListaAvion.h"

ListaAvion::ListaAvion() {

	primero = NULL;
	actual = NULL;
}
ListaAvion::~ListaAvion() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaAvion::insertar(Avion* avion) {

	actual = primero;


	if (primero == NULL) {
		primero = new NodoAvion(avion, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoAvion(avion, NULL));
		return true;
	}
	return false;
}
bool ListaAvion::listaVacia() {
	if (primero == NULL) return true;

	return false;
}

Avion* ListaAvion::buscar(string cod) {
	actual = primero;

	while (actual != NULL) {

		if (actual->getAvion()->getCodigo() == cod) {

			return actual->getAvion();
		}
		actual = actual->getSiguiente();

	}
	return NULL;
}

void ListaAvion::guardarAvion(string nom)
{
	ofstream salida(nom);
	
	actual = primero;
	while (actual != NULL) {

		actual->getAvion()->guardar(salida);
		
		actual = actual->getSiguiente();
	}
	salida.close();
}

string ListaAvion::toStringListaAvion() {

	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoAvion();
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}
