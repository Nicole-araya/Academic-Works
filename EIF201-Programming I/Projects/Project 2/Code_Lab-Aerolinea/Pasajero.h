#pragma once
#include "Persona.h"
class Pasajero :
    public Persona
{
private:

    string numAsiento;

public:

    Pasajero(string, string, string = " ");
    ~Pasajero();

    void setNumAsiento(string);
    string getNumAsiento();

    string toString();

};

