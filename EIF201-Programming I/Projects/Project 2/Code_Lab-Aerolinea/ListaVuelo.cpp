#include "ListaVuelo.h"

ListaVuelo::ListaVuelo() {
	primero = NULL;
	actual = NULL;
}
ListaVuelo::~ListaVuelo() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaVuelo::insertar(Vuelo* vuelo) {

	actual = primero;

	if (primero == NULL) {
		primero = new NodoVuelo(vuelo, NULL);
		return true;
	}
	else {
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new NodoVuelo(vuelo, NULL));
		return true;
	}
	return false;
}


bool ListaVuelo::listaVacia() {
	if (primero == NULL) return true;

	return false;
}

bool ListaVuelo::compararHora(string fecha, string hora, Avion* a)  
{
	actual = primero; 

	while (actual != NULL) {

		if (actual->getVuelo()->getFechaSalida() == fecha && actual->getVuelo()->getHoraSalida() == hora) {
			if (actual->getVuelo()->getAvion() == a) {
				return true;
			}
		}
		actual = actual->getSiguiente();

	}
	return false;

	
}

bool ListaVuelo::comparaSobrecargo(Vuelo* v, Sobrecargo* s, Sobrecargo* s2, Sobrecargo* s3)
{
	actual = primero;

	while (actual != NULL) {

		if (actual->getVuelo()->getCodigo() != v->getCodigo()) {  //QUE NO SE COMPARE ENTRE EL MISMO

			if (actual->getVuelo()->getFechaSalida() == v->getFechaSalida() && actual->getVuelo()->getHoraSalida() == v->getHoraSalida()) {

				if (actual->getVuelo()->comparaSobrecargoVuelo(s,s2,s3) == true) {
					return true;                                                         //se repite alguno
				}
			}
		}
		actual = actual->getSiguiente();
	}

	return false; //no se repite con ningun vuelo;
}

bool ListaVuelo::comparaCopilotoVuelo(Vuelo* v, Piloto* c, Piloto* c2)
{
	actual = primero;

	while (actual != NULL) {

		if (actual->getVuelo()->getCodigo() != v->getCodigo()) {  //QUE NO SE COMPARE ENTRE EL MISMO

			if (actual->getVuelo()->getFechaSalida() == v->getFechaSalida() && actual->getVuelo()->getHoraSalida() == v->getHoraSalida()) {

				if (actual->getVuelo()->compararCopilotoVuelo(c, c2) != false) {
					return true;                                                         //se repite alguno
				}
			}
		}
		actual = actual->getSiguiente();
	}

	return false; //no se repite con ningun vuelo;
}

bool ListaVuelo::comparaPilotoVuelo(string f, string h, Piloto* p)
{
	actual = primero;

	while (actual != NULL) {

		if (actual->getVuelo()->getFechaSalida() == f && actual->getVuelo()->getHoraSalida() == h) {

			if (actual->getVuelo()->compararPilotoVuelo(p) == true) {
				return true;                                                     // osea se repite alguno
			}
		}
		actual = actual->getSiguiente();
	}

	return false; //no se repite con ningun vuelo;
}



Vuelo* ListaVuelo::buscar(string cod) {
	actual = primero;

	while (actual != NULL) {

		if (actual->getVuelo()->getCodigo() == cod) {

			return actual->getVuelo();
		}
		actual = actual->getSiguiente();

	}
	return NULL;
}

string ListaVuelo::mostrarVueloDetallado(string cod)
{
	Vuelo* v = buscar(cod);
	
	stringstream s;

	if (v) {

		s << v->MostrarVueloDetallado();
	}
	else {
		s << "NO SE ENCONTRO VUELO" << endl;
	}
	
	
	return s.str();
}

string ListaVuelo::informacionVueloAsientos(string cod)
{
	Vuelo* v = buscar(cod);
	stringstream s;

	if (v != NULL) {

		s << v->capacidadYlistaPasajero();
	}
	else {
		s << "NO SE ENCONTRO VUELO" << endl;
	}

	return s.str();
}

string ListaVuelo::toStringListaVuelo() {

	actual = primero;
	stringstream s;

	if (listaVacia() != true) {

		while (actual != NULL) {

			s << actual->toStringNodoVuelo() << endl;
			actual = actual->getSiguiente();
		}
	}
	else {
		s << "Lista Vacia..." << endl;
	}

	return s.str();
}