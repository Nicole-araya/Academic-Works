#pragma once
#include"Ruta.h"
class NodoRuta
{
private:
    Ruta* r;
    NodoRuta* sig;
public:
    NodoRuta(Ruta*, NodoRuta*);

    virtual ~NodoRuta();

    void setRuta(Ruta*);
    Ruta* getRuta();
    void setSig(NodoRuta*);
    NodoRuta* getSig();
    string toStringNodoRuta();
};

