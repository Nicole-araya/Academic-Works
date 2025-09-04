#include "Ruta.h"

Ruta::Ruta(string cod,string origen, string destino, string duracion, int cant, double precio) {

	codigo = cod;
	lugarOrigen = origen;
	lugarDestino = destino;
	this->duracion = duracion;
	cantidadEscalas = cant;
	valorPasajeDolar = precio;
}

Ruta::~Ruta() {

}

void Ruta::setCodigo(string cod) {
	codigo = cod;
}

void Ruta::setLugarOrigen(string origen) {
	lugarOrigen = origen;
}
void Ruta::setLugardestino(string destino) {
	lugarDestino = destino;
}
void Ruta::setDuracion(string duracion) {
	this->duracion = duracion;
}
void Ruta::setCantidadEscalas(int cant) {
	cantidadEscalas = cant;
}
void Ruta::setValorPasajeDolar(double precio) {
	valorPasajeDolar = precio;
}
string Ruta::getCodigo() {
	return codigo;
}
string Ruta::getLugarOrigen() {
	return lugarOrigen;
}
string Ruta::getLugardestino() {
	return lugarDestino;
}
string Ruta::getDuracion() {
	return duracion;
}
int Ruta::getCantidadEscalas() {
	return cantidadEscalas;
}
double Ruta::getValorPasajeDolar() {
	return valorPasajeDolar;
}

void Ruta::guardar(ofstream& salida)
{
	salida << codigo << "\t";
	salida << lugarOrigen << "\t";
	salida << lugarDestino << "\t";
	salida << duracion << "\t";
	salida << cantidadEscalas << "\t";
	salida << valorPasajeDolar << "*";
}

string Ruta::toStringRuta() {
	stringstream s;

	s << "Codigo: " << codigo << endl;
	s << "Lugar de Origen: " << lugarOrigen << endl;
	s << "Lugar de Destino: " << lugarDestino << endl;
	s << "Duracion: " << duracion << endl;
	s << "Cantidad de Escalas: " << cantidadEscalas << endl;
	s << "Valor del Pasaje en Dolares: " << valorPasajeDolar << endl;

	return s.str();
}