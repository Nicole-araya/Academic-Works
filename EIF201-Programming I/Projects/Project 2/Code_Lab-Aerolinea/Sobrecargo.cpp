#include "Sobrecargo.h"

Sobrecargo::Sobrecargo(string nom, string id, int edad, string titulo, string telf, int grado):Tripulante(nom,id,edad) {

	this->titulo = titulo;
	telefono = telf;
	this->grado = grado;
}
Sobrecargo::~Sobrecargo() {

}

void Sobrecargo::setTitulo(string titulo) {
	this->titulo = titulo;
}
void Sobrecargo::setTelefono(string telf) {
	telefono = telf;
}
void Sobrecargo::setGrado(int grado) {
	this->grado = grado;
}
string Sobrecargo::getTitulo() {
	return titulo;
}
string Sobrecargo::getTelefono() {
	return telefono;
}
int Sobrecargo::getGrado() {
	return grado;
}

void Sobrecargo::guardar(ofstream& salida)
{
	salida << nombre << "\t";
	salida << id << "\t";
	salida << edad << "\t";
	salida << titulo << "\t";
	salida << telefono << "\t";
	salida << grado << "*";

}

string Sobrecargo::toString() {
	stringstream s;

	s << Tripulante::toString() << endl;
	s << " " << titulo << " Telfono: " << telefono << " Grado: " << grado << endl << endl;

	return s.str();
}