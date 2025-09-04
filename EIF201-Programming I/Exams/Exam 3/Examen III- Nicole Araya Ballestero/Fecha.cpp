#include"Fecha.h"

Fecha::Fecha(int d, int m, int a) {
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha() {
}

int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAnio() {
	return anio;
}

string Fecha::toString() const {
	stringstream s;
	s << dia << "/" << mes << "/" << anio ;
	return s.str();
}

