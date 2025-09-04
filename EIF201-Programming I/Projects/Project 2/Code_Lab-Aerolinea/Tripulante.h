#pragma once
#include "Persona.h"
class Tripulante :
    public Persona
{
protected:

    int edad;

public:

    Tripulante(string, string,int);
    ~Tripulante();
    void setEdad(int);
    int getEdad();

   string toString();
};

