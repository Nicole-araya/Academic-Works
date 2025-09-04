#include "Federaciones.h"

Federaciones::Federaciones()
{
    //ctor
}

Federaciones::~Federaciones()
{
    //dtor
}

void Federaciones::add(FIFA* f){

federacion.push_back(f);
}

string Federaciones::toString(){
stringstream s;

 for (int i = 0; i < federacion.size(); i++){

    s << federacion[i]->toString();
    }

return s.str();
}
