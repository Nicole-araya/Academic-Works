#include "NodoAvion.h"

NodoAvion::NodoAvion(Avion* info, NodoAvion* sig)
{
    this->info = info;
    this->sig = sig;
}

NodoAvion::~NodoAvion()
{
    delete info;
}

void NodoAvion::setAvion(Avion* info)
{
    this->info = info;
}

void NodoAvion::setSiguiente(NodoAvion* sig)
{
    this->sig = sig;
}

Avion* NodoAvion::getAvion()
{
    return info;
}

NodoAvion* NodoAvion::getSiguiente()
{
    return sig;
}

string NodoAvion::toStringNodoAvion()
{
    stringstream s;

    s << info->toStringAvion();

    return s.str();
}
