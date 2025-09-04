#include "Archivo.h"

Archivo::Archivo(string nom)
{
	nombre = nom;
}

Archivo::~Archivo()
{
}

void Archivo::setNombre(string nom)
{
	nombre = nom;
}

string Archivo::getNombre()
{
	return nombre;
}
