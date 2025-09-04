#include "Persona.h"



Persona::Persona(string nom, string id) {

	nombre = nom;
	this->id = id;
}

Persona::~Persona() {

}

void Persona::setNombre(string nom) {
	nombre = nom;
}
void Persona::setID(string id) {
	this->id = id;
}
string Persona::getNombre() {
	return nombre;
}
string Persona::getID() {
	return id;
}

string Persona::toString() {
	stringstream s;

	s << id << " " << nombre;

	return s.str();
}