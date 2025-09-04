#include "Metal.h"

Metal::Metal(string s) {

    simbolo = s;
}


Metal::~Metal() {}


string Metal::imprimirSimbolo() {

    return simbolo;
}

///////////////////////////////////////////////////////////////////

Hierro::Hierro(string s) :Metal(s) {}

Hierro::~Hierro() {}


string Hierro::imprimirSimbolo() { return  Metal::imprimirSimbolo(); }


/////////////////////////////////////////////////////////////////////

Plata::Plata(string s) :Metal(s) {}

Plata::~Plata(){}

string Plata::imprimirSimbolo() {
    return  Metal::imprimirSimbolo();
}

///////////////////////////////////////////////////////////////////////////

Oro::Oro(string s) :Metal(s) {}

Oro::~Oro(){}

string Oro::imprimirSimbolo() {
    return  Metal::imprimirSimbolo();
}