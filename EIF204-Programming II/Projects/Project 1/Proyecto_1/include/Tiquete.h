#pragma once
#include "Object.h"
#include "Ruta.h"
#include "RutaReservar.h"
class Tiquete :
    public Object
{
private:
    int cantidad;
    Ruta* ruta;
    string placabus;


public:

    Tiquete(string,Ruta*, int);
    ~Tiquete();

    void setPlaca(string);
    Ruta* getRuta();
    int getCan();
    string getPlaca();

    string Reservar();

    string toString();
};

