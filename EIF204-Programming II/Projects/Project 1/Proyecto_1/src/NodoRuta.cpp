#include "NodoRuta.h"

NodoRuta::NodoRuta(Ruta* r, NodoRuta* sig)
{
	this->r = r;
	this->sig = sig;
}

NodoRuta::~NodoRuta()
{
}

void NodoRuta::setRuta(Ruta* r)
{
	this->r =r;
}

Ruta* NodoRuta::getRuta()
{
	return r;
}

void NodoRuta::setSig(NodoRuta* sig)
{
	this->sig = sig;
}

NodoRuta* NodoRuta::getSig()
{
	return sig;
}

string NodoRuta::toStringNodoRuta()
{
	return r->toString();
}
