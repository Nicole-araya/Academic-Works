#include "ListaRuta.h"

ListaRuta::ListaRuta() {

	primero = NULL;
	actual = NULL;
}
ListaRuta::~ListaRuta() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaRuta::insertar(Ruta* ruta) {
	actual = primero;


	if (primero == NULL) {
		primero = new NodoRuta(ruta, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoRuta(ruta, NULL));
		return true;
	}

	return false;
}
bool ListaRuta::listaVacia() {
	if (primero == NULL) return true;

	return false;
}

Ruta* ListaRuta::buscar(string cod) {
	actual = primero;

	while (actual != NULL) {

		if (actual->getRuta()->getCodigo() == cod) {

			return actual->getRuta();
		}
		actual = actual->getSiguiente();

	}
	return NULL;
}

void ListaRuta::guardarRuta(string nom)
{
	ofstream salida(nom);

	actual = primero;
	while (actual != NULL) {

		actual->getRuta()->guardar(salida);

		actual = actual->getSiguiente();

	}
	salida.close();
}

string ListaRuta::toStringListaRuta() {

	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoRuta() << endl;
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}