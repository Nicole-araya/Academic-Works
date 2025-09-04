#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(int n,string no,float s,string b): Cuenta(n,no,s)
{
    beneficiario=b;
}

CuentaAhorros::~CuentaAhorros()
{
    //dtor
}

 string CuentaAhorros::getBeneficiario(){return beneficiario;}

void CuentaAhorros::retirar(float monto){

    if(saldo-monto >= 36000){
        saldo-=monto;
    }
    else{
            throw;
    }
        }

string CuentaAhorros::toString(){
    stringstream s;

    s<<"--- Cuenta de Ahorros ---"<<endl;
    s<<"Cuenta: "<< numCuenta<<" a nombre de "<<nombre<<endl;
    s<<"Beneficiario: "<< beneficiario<<endl<<endl;
    s<<"Saldo: "<< saldo<<endl<<endl;


    return s.str();
         }
