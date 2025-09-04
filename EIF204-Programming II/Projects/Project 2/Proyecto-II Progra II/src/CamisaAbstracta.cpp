#include "CamisaAbstracta.h"

CamisaAbstracta::CamisaAbstracta(string cod, double prec, string color){
	codigo = cod;
	precio = prec;
	this->color = color;
}

double CamisaAbstracta::getPrecio(){ return precio;}

CamisaAbstracta::~CamisaAbstracta()
{
}

void CamisaAbstracta::setPrecio(double precios){ this->precio = precios; }

string CamisaAbstracta::getdescripcion(){ return descripcion; }

string CamisaAbstracta::getCodigo()
{
	return codigo;
}


string CamisaAbstracta::getColor()
{
	return color;
}

bool CamisaAbstracta::getBoolOpc()
{
	return boolOpc;
}

void CamisaAbstracta::setBoolOpc(bool desc){ this->boolOpc = desc; }


