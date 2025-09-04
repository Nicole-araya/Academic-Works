#include "Cliente.h"

Cliente::Cliente(string ced, string nom, string correo, double pago, string ciudad, string pais)
{
	this->cedula = ced;
	this->nombre = nom;
	this->correo = correo;
	this->pagoSubscripcion = pago;
	this->ciudad = ciudad;
	this->pais = pais;
}

string Cliente::getCiudad(){ return this->ciudad;}

string Cliente::getPais(){ return this->pais; }

Cliente::~Cliente()
{
}

string Cliente::getNombre(){ return nombre; }

string Cliente::getCedula()
{
	return cedula;
}

string Cliente::getCorreo()
{
	return correo;
}

double Cliente::getPagoSubs()
{
	return pagoSubscripcion;
}

