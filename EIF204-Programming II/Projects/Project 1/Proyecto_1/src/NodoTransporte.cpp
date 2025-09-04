#include "NodoTransporte.h"

NodoTransporte::NodoTransporte(Transporte* t, NodoTransporte* sig)
{
	this->t = t;
	this->sig = sig;
}

NodoTransporte::~NodoTransporte()
{
}

void NodoTransporte::setTransporte(Transporte* t)
{
	this->t = t;
}

Transporte* NodoTransporte::getTransporte()
{
	return t;
}

void NodoTransporte::setSig(NodoTransporte* sig)
{
	this->sig = sig;
}

NodoTransporte* NodoTransporte::getSig()
{
	return sig;
}

string NodoTransporte::toStringNodoTransporte()
{
	return t->toString();
}
