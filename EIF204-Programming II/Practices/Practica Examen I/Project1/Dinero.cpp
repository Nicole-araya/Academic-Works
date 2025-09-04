#include "Dinero.h"
Dinero::Dinero(int v, int c)
{
    valor = v;
    can = c;

}

Dinero::~Dinero()
{
    //dtor
}

int Dinero::getValor() { return valor; }
int Dinero::getcan() { return can; }
void Dinero::setCan(int c) { can = c; }


///////////////////////////////////////////


Quinientos::Quinientos(int v, int c) :Dinero(v, c) {
}

Quinientos::~Quinientos() {}

////////////////////////////////


Cien::Cien(int v, int c) :Dinero(v, c) {
}
Cien::~Cien() {}

////////////////////////////////

Cincuenta::Cincuenta(int v, int c) :Dinero(v, c) {
}
Cincuenta::~Cincuenta() {}
