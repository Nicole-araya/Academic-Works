#include "Pasajero.h"

Pasajero::Pasajero(string nom, string id, string numero):Persona(nom,id) {

	numAsiento = numero;
}

Pasajero::~Pasajero() {

}

void Pasajero::setNumAsiento(string numero) {
	numAsiento = numero;
}
string Pasajero::getNumAsiento() {
	return numAsiento;
}

string Pasajero::toString() {
	stringstream s;

	s << Persona::toString();
	s << " " << numAsiento << endl;

	return s.str();
}
