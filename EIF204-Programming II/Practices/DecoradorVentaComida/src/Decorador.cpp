#include "Decorador.h"

Decorador::Decorador(VentaComida* co): comida(co)
{
    //ctor
}

Decorador::~Decorador()
{
    //dtor
}

string Decorador::descripcion(){
return comida->descripcion() ;

}
double Decorador::precio(){

return comida->precio(); }
