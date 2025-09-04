#ifndef LISTACUENTA_H
#define LISTACUENTA_H
#include "Nodo.h"

class ListaCuenta
{
    private:
    Nodo* primero;
    Nodo* actual;
public:
    ListaCuenta();
    ~ListaCuenta();
   void agregar(Cuenta*);
    string toString();
    bool estaVacia();
    Cuenta* busqueda(int);
};

#endif // LISTACUENTA_H
