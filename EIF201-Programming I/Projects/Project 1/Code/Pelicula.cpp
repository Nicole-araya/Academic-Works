#include "Pelicula.h"

Pelicula::Pelicula(string nom, string gen, string tip, string dim, string tipPub, string sip) {

	nombre = nom;
	genero = gen;
	tipo = tip;
	dimension = dim;
	tipoPublico = tipPub;
	sipnosis = sip;
}

Pelicula::~Pelicula() {

}

void Pelicula::setNombre(string nom) {
	nombre = nom;
}
void Pelicula::setGenero(string gen) {
	genero = gen;
}
void Pelicula::setTipo(string tip) {
	tipo = tip;
}
void Pelicula::setDimension(string dim) {
	dimension = dim;
}
void Pelicula::setTipoPublico(string tp) {
	tipoPublico = tp;
}
void Pelicula::setSipnosis(string sip) {
	sipnosis = sip;
}

string Pelicula::getNombre() {
	return nombre;
}
string Pelicula::getGenero() {
	return genero;
}
string Pelicula::getTipo() {
	return tipo;
}
string Pelicula::getDimension() {
	return dimension;
}
string Pelicula::getTipoPublico() {
	return tipoPublico;
}
string Pelicula::getSipnosis() {
	return sipnosis;
}

string Pelicula::toString() {
	stringstream s;

	s << "Pelicula " << endl;
	s << "--------------------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "Genero: " << genero << " Tipo de Publico: " << tipoPublico << endl;
	s << "Tipo: " << tipo << " Dimension: " << dimension << endl;
	s << "Sipnosis: " << sipnosis << endl;


	return s.str();
}