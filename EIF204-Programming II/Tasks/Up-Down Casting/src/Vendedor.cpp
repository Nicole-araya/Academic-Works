#include "Vendedor.h"

Vendedor::Vendedor(string n, string i,int s, int c,char ca): Empleado(n,i), Salario_Comision(s,c)
{
    categoria=ca;
}

Vendedor::~Vendedor()
{
    //dtor
}

void Vendedor::setCategoria(char ca){categoria=ca;}
int Vendedor::getCategoria(){return categoria;}

        string Vendedor::toString(){
        stringstream s;

        s<<Empleado::toString();
        s<<"Categoria: "<<categoria<<endl;
        s<<"Salario: "<<Salario_Comision::calcularSalarioTotal()<<endl;
        return s.str();

        }


