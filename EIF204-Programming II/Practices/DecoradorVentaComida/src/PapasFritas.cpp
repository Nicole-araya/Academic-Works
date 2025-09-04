#include "PapasFritas.h"

PapasFritas::PapasFritas(VentaComida* c): Decorador(c)
{
    //ctor
}

PapasFritas::~PapasFritas()
{
    //dtor
}

string PapasFritas::descripcion(){
return Decorador::descripcion() + " Papas Fritas " ;

}
double PapasFritas::precio(){

return Decorador::precio() + 200; }
