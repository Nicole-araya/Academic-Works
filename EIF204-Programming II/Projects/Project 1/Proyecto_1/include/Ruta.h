#pragma once
#include "Object.h"
#include "ListaTransporte.h"
class Ruta :
    public Object
{
private:
    string ruta;
    ListaTransporte* lt;

public:

    Ruta(string,string);
    virtual ~Ruta();
    void setRuta(string);
    string getRuta();
    ListaTransporte* getLista();

   void insertarTransporte(Transporte*);

    string imprimirBuses(); 

    virtual string toString(); 
};

