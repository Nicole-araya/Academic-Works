#include "Contacto.h"

Contacto::Contacto(string nom, int ed, string tel, string dir)
{
	nombre = nom;
	edad = ed;
	telefono = tel;
	direccion = dir;
}

Contacto::~Contacto()
{
}

void Contacto::setNombre(string nom)
{
	nombre = nom;
}

void Contacto::setEdad(int ed)
{
	edad = ed;
}

void Contacto::setTel(string tel)
{
	telefono = tel;
}

void Contacto::setDirec(string dir)
{
	direccion = dir;
}

string Contacto::getNombre()
{
	return nombre;
}

int Contacto::getEdad()
{
	return edad;
}

string Contacto::getTel()
{
	return telefono;
}

string Contacto::getDirec()
{
	return direccion;
}
