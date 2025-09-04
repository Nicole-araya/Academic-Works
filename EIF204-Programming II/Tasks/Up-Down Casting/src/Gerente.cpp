#include "Gerente.h"

Gerente::Gerente(string n, string i,int s,string a): Empleado(n,i), Salario(s)
{
   area=a;
}

Gerente::~Gerente()
{
    //dtor
}

 void Gerente::setArea(string a){ area=a;}
string Gerente::getArea(){return area;}

string Gerente::toString(){
stringstream s;

        s<<Empleado::toString();
        s<<"Area: "<<area<<endl;
        s<<"Salario: "<<Salario::getSalario()<<endl;
        return s.str();

        }
