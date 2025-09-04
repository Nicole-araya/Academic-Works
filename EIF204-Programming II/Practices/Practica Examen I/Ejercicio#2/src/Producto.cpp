#include "Producto.h"


Producto::Producto(string nom, int c, int p)
{
    nombre = nom;
    can = c;
    precio = p;
}

Producto::~Producto()
{
    //dtor
}

void Producto::setCan(int c) {
    can = c;
}

string Producto::toString() {
    stringstream s;

    s << nombre << "  "
        << precio << endl;

    return s.str();
}



int Producto::getCan() { return can; }
int Producto::getPrecio() { return precio; }

int Producto::disponible() {

    if (can == 0) { return 0; }
    else can--;
}
