#include "Salario.h"

Salario::Salario(int s)
{
    saldo=s;
}

Salario::~Salario()
{
    //dtor
}
 int Salario::getSalario(){
 return saldo;}

//-------------------------------
Salario_Comision::Salario_Comision(int s, int c):Salario(s){

    comision=c;
}
Salario_Comision::~Salario_Comision(){ }

int Salario_Comision::calcularSalarioTotal(){

return comision+ Salario::getSalario();
}
