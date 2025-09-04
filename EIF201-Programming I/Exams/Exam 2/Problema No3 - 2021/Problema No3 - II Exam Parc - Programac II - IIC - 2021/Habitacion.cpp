#include"Habitacion.h"

Habitacion::Habitacion(){
	numHabitacion = 0;
	numCamasAdult = 2;
	numCamasNinos = 3;
	 estado = 'D';
	 desc = false;
}


Habitacion::~Habitacion(){}

void Habitacion::setNumHabitacion(int n) { 
	numHabitacion = n; }

void Habitacion::setEstado(char mant) { 
	estado = mant; }

void Habitacion::setDesc(bool des) { 
	desc = des; }

int Habitacion::getNumHabitacion() {
	return numHabitacion; }

char Habitacion::getEstado() { 
	return estado; }

bool Habitacion::getDesc() {
	return desc; }



string Habitacion::toString() const {
	stringstream s;
	s << "[Hab: " << numHabitacion << " Est: " << estado<<"] ";
	return s.str();
}