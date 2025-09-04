#pragma once
#include "NodoTiquete.h"
#include "TiquteBDatos.h"
class ListaTiquete
{
private:
    NodoTiquete* primero;
    NodoTiquete* actual;
public:

    ListaTiquete();
    ~ListaTiquete();
    void agregar(Tiquete*);
    string toString();
    bool estaVacia();

    Tiquete* busqueda(string);

    void guardar(string);
};

