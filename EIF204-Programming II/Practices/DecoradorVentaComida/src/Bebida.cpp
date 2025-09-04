#include "Bebida.h"

Bebida::Bebida(VentaComida* c): Decorador(c)
{
    //ctor
}

Bebida::~Bebida()
{
    //dtor
}

string Bebida::descripcion(){
return Decorador::descripcion() + " Bebida " ;

}
double Bebida::precio(){

return Decorador::precio() + 350; }
