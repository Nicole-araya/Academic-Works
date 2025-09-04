#include "NodoTiquete.h"

NodoTiquete::NodoTiquete(Tiquete* t, NodoTiquete* sig)
{
	this->t = t;
	this->sig = sig;
}

NodoTiquete::~NodoTiquete()
{
}

void NodoTiquete::setTiquete(Tiquete* t)
{
	this->t = t;
}

Tiquete* NodoTiquete::getTiquete()
{
	return t;
}

void NodoTiquete::setSig(NodoTiquete* sig)
{
	this->sig = sig;
}

NodoTiquete* NodoTiquete::getSig()
{
	return sig;
}

string NodoTiquete::toStringNodoTiquete()
{
	return t->toString();
}