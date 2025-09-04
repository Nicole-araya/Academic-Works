#pragma once
#include "Object.h"

class Transporte :
    public Object
{
protected:
    string nombre;
    int numAsientos;
    int can;
    char** asientos;

public:

    Transporte(string, string, int);
    virtual ~Transporte();

    void setNombre(string);
    void setNumAsientos(int);

    string getNombre();
    int getNumAsientos();
    int getCan();

    virtual bool reservar();
    virtual string imprimirAsientos();

    virtual string toString();

};

