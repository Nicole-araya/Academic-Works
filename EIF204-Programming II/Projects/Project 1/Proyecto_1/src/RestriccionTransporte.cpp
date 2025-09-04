#include "RestriccionTransporte.h"

RestriccionTransporte::RestriccionTransporte(string i, string n, int c) :Transporte(i, n, c)
{
	porcetajeRestriccion = 100;
	tamDisponible = 0;
	
}

RestriccionTransporte::~RestriccionTransporte()
{
}

void RestriccionTransporte::setPorcentaje(int p)
{
	porcetajeRestriccion = p;
}

void RestriccionTransporte::setTamDisponible(int t)
{
	tamDisponible = t;
}

int RestriccionTransporte::getPorcentaje()
{
	return porcetajeRestriccion;
}


int RestriccionTransporte::getTamDisponible()
{
	tamDisponible= ((double)getPorcentaje() / 100)* numAsientos;
	return tamDisponible;
}

bool RestriccionTransporte::reservar()
{
	char* O = new char('O');  //char de OCUPADO

	if (can < tamDisponible) {

		asientos[can++] = O;

		return true;
	}

	return false;
}

string RestriccionTransporte::imprimirAsientos()   // para enseñar asientos, era una prueba
{
	stringstream s;

	int contador = 0;

	for (int i = 0; i < tamDisponible; i++) {

		if (contador < 6) { 
			s << *asientos[i] <<'\t';  contador++; 
		}
		else {
			s << *asientos[i]<< endl; contador = 0;
		}
	}
	return s.str();
}



string RestriccionTransporte::toString()
{
	stringstream s;

	s << Transporte::toString()
	<< ", Restriccion de capacidad " << porcetajeRestriccion<<"% "
	<< ", capacidad de " << tamDisponible << " asientos" << endl;

	return s.str();
}
