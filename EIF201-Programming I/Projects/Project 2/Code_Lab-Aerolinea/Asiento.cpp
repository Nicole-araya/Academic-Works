#include "Asiento.h"

Asiento::Asiento(int fila, int colum) {

	this->fila = fila;
	columna = colum;

	asiento = new string * *[fila];	

	for (int i = 0; i < fila;i++) {

		asiento[i] = new string * [columna];
	}

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			asiento[i][j] = NULL;
		}
	}


}

Asiento::~Asiento() {

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			delete asiento[i][j];
		}
	}
	for (int i = 0;i < fila;i++) {

		delete[] asiento[i];
	}
	delete[] asiento;
}



int Asiento::getFila() {
	return fila;
}
int Asiento::getColumna() {
	return columna;
}


string* Asiento::insertarEstadoAsiento() {

	string* estado = new string("Ocupado");

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			if (asiento[i][j] == NULL) {

				asiento[i][j] = estado;

				return asiento[i][j];
			}

		}
	}

	return NULL;
}

int Asiento::contadorAsiento() {

	int totalAsientos = 0;

	for (int i = 0;i < fila;i++) {

		totalAsientos++;
		for (int j = 0;j < columna;j++) {

			totalAsientos++;

		}
	}

	return totalAsientos;
}
int Asiento::contadorAsientoDisponibles() {

	int asientoDisponible = 0;
	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			if (asiento[i][j] == NULL) {
				asientoDisponible++;
			}
		}
	}

	return asientoDisponible;
}


int Asiento::retornaNumeroFila(char) {

}

char Asiento::retornaLetraFila(int){

}

string Asiento::toString(){

	stringstream s;

	s << "Asientos: " << endl;
	s << "------------------------" << endl << endl;

	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {

			s << retornaLetraFila(i);
			s << j << endl;


			if (asiento[i][j] == NULL) {

				s << "Disponible\n";
		
			}
			else {

				s << *asiento[i][j] << endl;
			}

		}
	}


	return s.str();

}