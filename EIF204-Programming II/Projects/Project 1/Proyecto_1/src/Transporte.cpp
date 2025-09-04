#include "Transporte.h"

Transporte::Transporte(string i, string n, int c):Object(i)
{
	nombre = n;
	numAsientos = c;
	can = 0;
	asientos = new char* [numAsientos];

	for (int i = 0; i < numAsientos;i++) {
		asientos[i] = new char('D');         //char de DISPONIBLE
	}
	
}

Transporte::~Transporte()
{
	for (int i = 0;i < numAsientos;i++) {
		delete asientos[i];
	}
	delete[] asientos;
}

void Transporte::setNombre(string n)
{
	nombre = n;
}

void Transporte::setNumAsientos(int c)
{
	numAsientos = c;
}


string Transporte::getNombre()
{
	return nombre;
}

int Transporte::getNumAsientos()
{
	return  numAsientos;
}


int Transporte::getCan()
{
	return can;
}

bool Transporte::reservar()
{
	return false;
}

string Transporte::imprimirAsientos()
{
	stringstream s;

	cout << "Vacio" << endl;
	return s.str();
}

string Transporte::toString()
{
	stringstream s;

	s << identificador
		<< ", " << nombre
		<< ", " << numAsientos << " asientos";

	return s.str();

}
