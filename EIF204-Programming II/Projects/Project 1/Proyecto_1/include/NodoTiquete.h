#pragma once
#include "Tiquete.h"
class NodoTiquete
{
private:
    Tiquete* t;
    NodoTiquete* sig;
public:
    NodoTiquete(Tiquete*, NodoTiquete*);

    virtual ~NodoTiquete();

    void setTiquete(Tiquete*);
    Tiquete* getTiquete();
    void setSig(NodoTiquete*);
    NodoTiquete* getSig();
    string toStringNodoTiquete();
};

