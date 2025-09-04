#include "Persona.h"

Persona::Persona(int id, string nom, string direc)
{
	this->id = id;
	nombre = nom;
	direccion = direc;
}

Persona::~Persona()
{
}

int Persona::getID()
{
	return id;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getDireccion()
{
	return direccion;
}

void Persona::setID(int id)
{
	this->id = id;
}

void Persona::setNombre(string nom)
{
	nombre = nom;
}

void Persona::setDireccion(string direc)
{
	direccion = direc;
}

string Persona::toString()
{
	stringstream s;

	s << id << ", " << nombre << ", " << direccion << endl;
	return s.str();
}
