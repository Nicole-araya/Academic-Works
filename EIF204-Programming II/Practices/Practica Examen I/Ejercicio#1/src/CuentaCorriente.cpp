#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int n,string no,float s): Cuenta(n,no,s)
{
    //ctor
}

CuentaCorriente::~CuentaCorriente()
{
    //dtor
}

 void CuentaCorriente::retirar(float monto){

 if(saldo-monto < 0){

    saldo-=monto;

 }else throw;


 }

string CuentaCorriente::toString(){
    stringstream s;

    s<<"--- Cuenta de Ahorros ---"<<endl;
    s<<"Cuenta: "<< numCuenta<<" a nombre de "<<nombre<<endl;
    s<<"Saldo: "<<saldo<<endl<<endl;


    return s.str();
    }
