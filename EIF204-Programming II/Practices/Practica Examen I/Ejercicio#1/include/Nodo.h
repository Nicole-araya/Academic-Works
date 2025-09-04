#ifndef NODO_H
#define NODO_H
#include "Cuenta.h"

class Nodo
{
    private:
    Cuenta *info;
    Nodo* sig;
public:
    Nodo(Cuenta *, Nodo*);

    virtual ~Nodo();

    void setCuenta(Cuenta*);
    Cuenta* getCuenta();
    void setSig(Nodo*);
    Nodo* getSig();
    string toStringNodo();
};

#endif // NODO_H
