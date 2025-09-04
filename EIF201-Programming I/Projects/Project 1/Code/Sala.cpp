#include "Sala.h"



Sala::Sala(string tip) {

	tipo = tip;

	fila = maxFila;
	columna = maxColumna;

	asiento = new string **[fila];

	for (int i = 0; i < fila;i++) {

		asiento[i] = new string *[columna];
	}

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			asiento[i][j] = NULL;
		}
	}


}

Sala::~Sala() {

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			delete asiento[i][j] ;
		}
	}
	for (int i = 0;i < fila;i++) {

		delete[] asiento[i];

	}

	delete[] asiento;

	cout << "DESTRUIDO" << endl;
}

void Sala::setTipo(string tip) {
	tipo = tip;
}



string Sala::getTipo() {
	return tipo;
}
int Sala::getFila() {
	return fila;
}
int Sala::getColumna() {
	return columna;
}

bool Sala::insertarEstadoAsiento(char i, int j, string* estado) {

	int k = retornaNumeroFila(i);

	if (asiento[k][j] != NULL) {          //si esta ocupado

		return false;
	}

	if (asiento[k][j] == NULL) {               //Si no esta ocupado

		asiento[k][j] = estado;
		return true;

	}
}

void Sala::confirmacionEstadoAsiento( char opcion, string* estado, string* estado2) {

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {


			if (opcion == 's' || opcion == 'S') {          //Si confirma el asiento
				if (asiento[i][j] == estado) {

					asiento[i][j] = estado2;


				}
			}
			else {                                        //Si no confirma el asiento
				if (asiento[i][j] == estado) {

					asiento[i][j] = NULL;


				}
			}
		}
	}

                              
}
bool Sala::confirmacionCompra(char i, int j, char op) {

	int k = retornaNumeroFila(i);

	if ( op =='n'|| op == 'N') {          //Si no compra el asiento

		asiento[k][j] = NULL;

		return false;
	}

							//Si se confirma la compra

		return true;


}

int Sala::contadorAsientoDisponibles() {

	int contador = 0;

	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {

			if (asiento[i][j] == NULL) {

				contador++;
			}

		}
	}

	return contador;

}


int Sala::retornaNumeroFila(char i) {

	if (i == 'A') {
		return 0;
	}
	if (i == 'B') {
		return 1;
	}
	if (i == 'C') {
		return 2;
	}
	if (i == 'D') {
		return 3;
	}
	if (i == 'E') {
		return 4;
	}
	if (i == 'F') {
		return 5;
	}

}

char Sala::retornaLetraFila(int i) {

	if (i == 0) {
		return 'A';
	}
	if (i == 1) {
		return 'B';
	}
	if (i == 2) {
		return 'C';
	}
	if (i == 3) {
		return 'D';
	}
	if (i == 4) {
		return 'E';
	}
	if (i == 5) {
		return 'F';
	}

}


string Sala::toString() {
	stringstream s;

	s << "------------------------" << endl;
	s << " Sala: " << tipo<<endl;
	s << "------------------------" << endl<<endl;

	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {

			s << retornaLetraFila(i);
			s << j << endl;


			if (asiento[i][j] == NULL) {


				s << ANSI_COLOR_GREEN;
				s<<"Disponible\n";
				s << ANSI_COLOR_RESET;

			}
			else {

				if (*asiento[i][j] == "Ocupado") {

					s << ANSI_COLOR_RED;
					s << *asiento[i][j] << endl;
					s << ANSI_COLOR_RESET;
				}
				else {

					s << *asiento[i][j] << endl;

				}

			}


		}
	}
	

	return s.str();
}