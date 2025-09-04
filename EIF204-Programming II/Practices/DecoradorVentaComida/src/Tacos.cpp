#include "Tacos.h"

Tacos::Tacos(VentaComida* c): Decorador(c)
{
    //ctor
}

Tacos::~Tacos()
{
    //dtor
}

string Tacos::descripcion(){
return Decorador::descripcion() + " Tacos " ;

}
double Tacos::precio(){

return Decorador::precio() + 400; }
