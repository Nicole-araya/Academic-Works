#include "Nodo.h"

Nodo::Nodo(Cuenta *c, Nodo * sig) {
    this->info=c;
    this->sig=sig;
}

void Nodo::setCuenta(Cuenta *c) {
    info=c;
}

Cuenta* Nodo::getCuenta() {
    return info;
}

void Nodo::setSig(Nodo *sig) {
    this->sig=sig;
}

Nodo *Nodo::getSig() {
    return sig;
}

string Nodo::toStringNodo() {
    return info->toString();
}

Nodo::~Nodo() {
    delete info;
}
