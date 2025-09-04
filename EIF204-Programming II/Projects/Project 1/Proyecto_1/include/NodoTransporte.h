#pragma once
#include "Transporte.h"
class NodoTransporte
{
private:
    Transporte* t;
    NodoTransporte* sig;
public:
    NodoTransporte(Transporte*, NodoTransporte*);

    virtual ~NodoTransporte();

    void setTransporte(Transporte*);
    Transporte* getTransporte();
    void setSig(NodoTransporte*);
    NodoTransporte* getSig();
    string toStringNodoTransporte();
};

