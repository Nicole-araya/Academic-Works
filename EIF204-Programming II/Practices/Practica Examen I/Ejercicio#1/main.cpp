#include <iostream>
#include"CuentaCorriente.h"
#include "CuentaAhorros.h"
#include "Cuenta.h"
#include "Banco.h"
using namespace std;

int main()
{
    Banco* b=new Banco();

    b->ingresarCuenta(new CuentaAhorros(111,"Nicole",40000,"Marcela"));
    b->ingresarCuenta(new CuentaCorriente(222,"Juan",50000));
    b->ingresarCuenta(new CuentaAhorros(333,"Maria",60000,"Rodrigo"));


    b->menu();


    return 0;
}
