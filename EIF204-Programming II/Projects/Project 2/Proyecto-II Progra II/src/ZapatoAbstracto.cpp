#include "ZapatoAbstracto.h"


ZapatoAbstracto::ZapatoAbstracto(string cod, double prec, string color)
{
	codigo = cod;
	precio = prec;
	this->color = color;
}

double ZapatoAbstracto::getPrecio(){return precio;}

ZapatoAbstracto::~ZapatoAbstracto()
{
}

void ZapatoAbstracto::setPrecio(double precios){ this->precio = precios; }

string ZapatoAbstracto::getdescripcion(){	return descripcion;}

string ZapatoAbstracto::getCodigo()
{
	return codigo;
}


string ZapatoAbstracto::getColor()
{
	return color;
}

bool ZapatoAbstracto::getBoolOpc()
{
	return boolOpc;
}

void ZapatoAbstracto::setOpc(bool opc){ this->boolOpc = opc; }
