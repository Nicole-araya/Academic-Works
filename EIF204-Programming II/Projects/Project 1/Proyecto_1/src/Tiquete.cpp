#include "Tiquete.h"

Tiquete::Tiquete(string i,Ruta* r,int c):Object(i)
{
	ruta = r; cantidad = c; placabus = "";
}

Tiquete::~Tiquete()
{
}

void Tiquete::setPlaca(string p)
{
	placabus = p;
}

Ruta* Tiquete::getRuta()
{
	return ruta;
}

int Tiquete::getCan()
{
	return cantidad;
}

string Tiquete::getPlaca()
{
	return placabus;
}

string Tiquete::Reservar() 
{ 
	Transporte* t = NULL; 

	if (t = RutaReservar::reservar(ruta)) { 
		
		return t->getIdentificador();
	}
	else return "";
}

string Tiquete::toString()
{
	stringstream s;

	s << identificador << ", cantidad: " << cantidad << ", " << ruta->getRuta() << ", " << placabus << endl;

	return s.str();
}
