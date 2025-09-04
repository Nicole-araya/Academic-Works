#include "ColeccionPF.h"

ColeccionPF::ColeccionPF(int tamP, int tamF) {

	tamFunc = tamF;
	canFunc = 0;
	funcion = new Funcion* [tamFunc];

	for (int i = 0; i<tamFunc;i++) {
		funcion[i] = NULL;
	}


	tamPeli = tamP;
	canPeli = 0;
	pelicula = new Pelicula* [tamPeli];

	for (int i = 0;i<tamPeli;i++) {
		pelicula[i] = NULL;
	}
}

ColeccionPF::~ColeccionPF() {

	for (int i = 0;tamFunc;i++) {
		delete funcion[i];
	}
	for (int i = 0;tamPeli;i++) {
		delete pelicula[i];
	}

	delete[] funcion, pelicula;

}

int ColeccionPF::getTamFun() {
	return tamFunc;
}
int ColeccionPF::getTamPeli() {
	return tamPeli;
}
int ColeccionPF:: getCanFun() {
	return canFunc;
}
int ColeccionPF::getCanPeli() {
	return canPeli;
}


void  ColeccionPF::setTamFun(int tf) {
	tamFunc = tf;
}
void  ColeccionPF::setTamPeli(int tp) {
	tamPeli = tp;
}

bool ColeccionPF::insertarPelicula(Pelicula* peli) {

	                                                       //No se puede repetir la pelicula
	
	for (int i = 0;i < canPeli;i++) {
		if (buscarPeliPosicion(i)->getNombre() == peli->getNombre()) {

		cout << "YA EXISTE LA PELICULA " << endl;
			return false;
		}
	}                                                 //Si no existe aun la pelicula se inserta
	
	if (canPeli < tamPeli) {

		pelicula[canPeli++] = peli;

		cout << "SE AGREGO PELICULA " << endl;
		return true;
	}

	cout << "NO SE PUDO AGREGAR PELICULA " << endl;
	return false;
}
bool ColeccionPF::insertarFuncion(Funcion* fun) {

	if (canFunc < tamFunc) {

		funcion[canFunc] = fun;

		canFunc++;
		return true;
	}

	return false;
}

Funcion* ColeccionPF::buscarFuncionxGenero(string genero) {

	for (int i = 0;i < canFunc;i++) {       //Si existe una, hay funciones con peliculas de ese genero

		if (funcion[i]->getPelicula()->getGenero() == genero) {

			return funcion[i];
		}
	}

	return NULL;
}

Pelicula* ColeccionPF::buscarPeliPosicion(int k) {

	for (int i = 0;i < canPeli;i++) {

		if (i == k) {

			return pelicula[i];
		}
	}

	return NULL;
}


Funcion* ColeccionPF::buscarFuncion(string fecha) {

	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getFecha() == fecha) {

			return funcion[i];
		}
	}

	return NULL;
}
Funcion* ColeccionPF::buscarFuncionPosicion(int k) {

	for (int i = 0;i < canFunc;i++) {

		if (i == k) {

			return funcion[i];
		}
	}
	return NULL;
}

Funcion* ColeccionPF::buscarFuncionxPeli(int k) {

	Pelicula* p = buscarPeliPosicion(k);        //Si existe una, hay funciones con esa pelicula

	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getPelicula()->getNombre() == p->getNombre()) {

			return funcion[i];
		}
	}

	return NULL;
}

void ColeccionPF::eliminarPelicula(int k) {

	Pelicula* p = buscarPeliPosicion(k);

	for (int i = 0;i < canPeli;i++) {

		if ( pelicula[i] == p ) {

			delete pelicula[i];
			int j = i;                                        //Corrimiento

			if (pelicula[j] == pelicula[canPeli-1]) {    // Si fuera la ultima posicion

				pelicula[canPeli-1] = NULL;
				canPeli--;

				cout << "SE ELIMINO EXITOSAMENTE PELICULA" << endl;
			}
			else {
				for (j; j < canPeli;j++) {           // Cualquier otra posicion menos la ultima

					pelicula[j] = pelicula[j + 1];
					pelicula[canPeli -1] = NULL;
					canPeli--;

					cout << "SE ELIMINO EXITOSAMENTE PELICULA" << endl;
				}
			}
		}

	}
}

void ColeccionPF::eliminarFuncion(string fecha) {


	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getFecha() == fecha) {

			delete funcion[i];
			int j = i;                                        //Corrimiento

			if (funcion[j] == funcion[canFunc-1]) {    // Si fuera la ultima posicion

				funcion[canFunc-1] = NULL;
				canFunc--;

				cout << "SE ELIMINO EXITOSAMENTE FUNCION" << endl;
			}
			else {
				for (j; j < canFunc;j++) {           // Cualquier otra posicion menos la ultima

					funcion[j] = funcion[j + 1];
					funcion[canFunc-1] = NULL;
					canFunc--;

					cout << "SE ELIMINO EXITOSAMENTE FUNCION" << endl;
				}
			}
		}

	}
}

void ColeccionPF::eliminarFuncionxPeli(int k) {

	Pelicula* p= buscarPeliPosicion(k);

	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getPelicula()->getNombre() == p->getNombre()) {

			delete funcion[i];
			int j = i;                                        //Corrimiento

			if (funcion[j] == funcion[canFunc-1]) {    // Si fuera la ultima posicion

				funcion[canFunc-1] = NULL;
				canFunc--;

				cout << "SE ELIMINO EXITOSAMENTE FUNCION" << endl;
			}
			else {
				for (j; j < canFunc;j++) {           // Cualquier otra posicion menos la ultima

					funcion[j] = funcion[j + 1];
					funcion[canFunc-1] = NULL;
					canFunc--;

					cout << "SE ELIMINO EXITOSAMENTE FUNCION" << endl;
				}
			}
		}

	}
}

bool ColeccionPF::funcionMaxDia(string fecha) {

	int funcionxDia = 0;
	
	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getFecha() == fecha ) {
				funcionxDia++;
		}
	}

	if (funcionxDia != 2) {
		return true;
	}

	return false;

}

bool ColeccionPF::vectorVacioPeli() {

	if (pelicula[0] == NULL) {         //Si en la primera posicion no hay nada el vector esta vacio
		return true;
	}

		return false;
}

bool ColeccionPF::vectorVacioFuncion() {
	if (funcion[0] == NULL) {         //Si en la primera posicion no hay nada el vector esta vacio
		return true;
	}

	return false;
}
bool ColeccionPF::disponibilidadSala(int num, string fecha) {

	if (num == 1) {        //SALA VIP

		for (int i = 0;i < canFunc;i++) {      // con que haya una sala ocupada el mismo dia se termina el ciclo

			if (funcion[i]->getSala()->getTipo() == "VIP" && funcion[i]->getFecha() == fecha) {

				return false;
			}
		}
		return true;
	}
	else {
		if (num == 2) {          //SALA REGULAR

			for (int i = 0;i < canFunc;i++) {      // con que haya una sala ocupada el mismo dia se termina el ciclo

				if (funcion[i]->getSala()->getTipo() == "Regular" && funcion[i]->getFecha() == fecha) {

					return false;
				}
			}
			return true;
		}

	}
}


string ColeccionPF::ImprimirPelicula(){
	stringstream s;

	for (int i = 0;i < canPeli;i++) {

		s << "--------------------" << endl;
		s << i << ". " << pelicula[i]->toString();
		s << endl << endl;
	}

	return s.str();
}

string ColeccionPF::ImprimirFuncionesxGenero( string genero) {

	stringstream s;

	for (int i = 0;i < canFunc;i++) {

		if (funcion[i]->getPelicula()->getGenero() == genero) {

			s << "--------------------" << endl;
			s << i << ". " << funcion[i]->toString();
			s << endl << endl;

		}
	}

	return s.str();

}


string ColeccionPF::ImprimirFuncion() {
	stringstream s;

	for (int i = 0; i< canFunc; i++) {

		s << "---------------------------" << endl;
		s << i << ". " << funcion[i]->toString();
		s << endl << endl;
	}


	return s.str();
}

string ColeccionPF::ImprimirFuncionxFecha(string fecha) {
	stringstream s;

	for (int i = 0; i < canFunc; i++) {

		if (funcion[i]->getFecha() == fecha) {

			s << "--------------------" << endl;
			s << i << ". " << funcion[i]->toString();
			s << endl << endl;

		}
	}

	return s.str();
}