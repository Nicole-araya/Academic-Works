#include "Cuenta.h"

Cuenta::Cuenta(int n,string no,float s)
{
    numCuenta=n;
    nombre=no;
    saldo=s;
}

Cuenta::~Cuenta()
{
    //dtor
}

 int Cuenta::getNumCuenta(){return numCuenta;}
string Cuenta::getNombre(){return nombre;}
float Cuenta::getSaldo(){return saldo;}

void Cuenta::consignar(float monto){

    saldo += monto;

}
