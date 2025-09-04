#include "Hamburguesa.h"

Hamburguesa::Hamburguesa(VentaComida* c): Decorador(c)
{
    //ctor
}

Hamburguesa::~Hamburguesa()
{
    //dtor
}

string Hamburguesa::descripcion(){
return Decorador::descripcion() + " Hamburguesa " ;

}
double Hamburguesa::precio(){

return Decorador::precio() + 500; }
