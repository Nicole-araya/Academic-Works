#include "PantalonAbstracto.h"

PantalonAbstracto::PantalonAbstracto(string cod, double prec, string color)
{
	codigo = cod;
	precio = prec;
	this->color = color;
}

double PantalonAbstracto::getPrecio(){ return precio;}

PantalonAbstracto::~PantalonAbstracto()
{
}

void PantalonAbstracto::setPrecio(double precios){ this->precio = precios; }

string PantalonAbstracto::getdescripcion(){	return descripcion;}

string PantalonAbstracto::getCodigo()
{
	return codigo;
}

string PantalonAbstracto::getColor()
{
	return color;
}

bool PantalonAbstracto::getBoolOpc()
{
	return boolOpc;
}

void PantalonAbstracto::setBoolOpc(bool opc){ this->boolOpc = opc; }
