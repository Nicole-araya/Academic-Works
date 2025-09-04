#include "Vacuna.h"

Vacuna::Vacuna(int nl, int ns, string fv, string fa, string cc) {
	numLote = nl;
	numSerie = ns;
	fechaVencimiento = fv;
	fechaAplicacion = fa;
	casaComercial = cc;
}

int  Vacuna::getNumLote() {
	return numLote;
}
int Vacuna::getNumSerie() {
	return numSerie;
}
string Vacuna::getFechaVencimiento() {
	return fechaVencimiento;
}
string Vacuna::getFechaAplicacion() {
	return fechaAplicacion;
}
string Vacuna::getCasaComercial() {
	return fechaAplicacion;
}

void Vacuna::setNumLote(int nl) {
	numLote = nl;
}
void Vacuna::setNumSerie(int ns) {
	numSerie = ns;
}
void Vacuna::setFechaVencimiento(string fv) {
	fechaVencimiento = fv;
}
void Vacuna::setFechaAplicacion(string fa) {
	fechaAplicacion = fa;
}
void Vacuna::setCasaComercial(string cc) {
	fechaAplicacion = cc;
}

string Vacuna::toString() {
	stringstream s;

	s << "---------------" << endl;
	s << "     VACUNA    " << endl;
	s << "---------------" << endl;
	s << "Numero de lote: " << numLote << endl;
	s << "Numero de Serie: " << numSerie << endl;
	s << "Fecha de Vencimiento: " << fechaVencimiento << endl;
	s << "Fecha de Aplicacion: " << fechaAplicacion << endl;
	s << "Casa Comercial: " << casaComercial << endl;


	return s.str();
}