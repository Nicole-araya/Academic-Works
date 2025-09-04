#include "Tripulante.h"

Tripulante::Tripulante(string nom, string id, int edad):Persona(nom,id) {
	this->edad = edad;
}

Tripulante::~Tripulante() {

}

void Tripulante::setEdad(int edad) {
	this->edad = edad;
}
int Tripulante::getEdad() {
	return edad;
}

string Tripulante::toString() {
	stringstream s;

	s << Persona::toString()<<endl;
	s << "Edad: " << edad;

	return s.str();
}