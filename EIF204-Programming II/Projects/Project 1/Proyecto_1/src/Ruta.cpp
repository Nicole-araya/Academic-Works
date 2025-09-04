#include "Ruta.h"

Ruta::Ruta(string i, string r) :Object(i)
{
	ruta = r;
	lt = new ListaTransporte();
}

Ruta::~Ruta()
{
	delete lt;
}

void Ruta::setRuta(string r)
{
	ruta = r;
}

string Ruta::getRuta()
{
	return ruta;
}

ListaTransporte* Ruta::getLista()
{
	return lt;
}

void Ruta::insertarTransporte(Transporte* t)
{
	lt->agregar(t);


}

string Ruta::imprimirBuses()
{
	stringstream s;

	s << "**** Lista de Buses *****" << endl
		<< lt->toString() << endl;

	return s.str();
}

string Ruta::toString()
{
	stringstream s;

	s << identificador
		<< ", " << ruta;

	return s.str();
}
