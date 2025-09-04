#include "VentaComida.h"

VentaComida::VentaComida()
{
    //ctor
}

VentaComida::~VentaComida()
{
    //dtor
}

string VentaComida::toStringIVA(){
stringstream s;

s<<descripcion()<<" : "<< precio()*0.13+ precio();

return s.str();}


string VentaComida::toStringSINIVA(){
stringstream s;

s<<descripcion()<<" : "<< precio();

return s.str();}
