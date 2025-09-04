#pragma once
#include "Transporte.h"
class RestriccionTransporte :
    public Transporte
{
private:
    int porcetajeRestriccion;
    int tamDisponible;

public:
    RestriccionTransporte(string, string, int);
    ~RestriccionTransporte();

    void setPorcentaje(int);
    void setTamDisponible(int);
    int getPorcentaje();
    int getTamDisponible();


    bool reservar();
    string imprimirAsientos();

    string toString();
};

