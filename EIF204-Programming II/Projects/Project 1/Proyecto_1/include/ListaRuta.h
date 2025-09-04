#pragma once
#include "NodoRuta.h"
#include "RutaReservar.h"
#include "RutaBDatos.h"

class ListaRuta
{
private:
    NodoRuta* primero;
    NodoRuta* actual;
public:

    ListaRuta();
    ~ListaRuta();
    void agregar(Ruta*);
    string toString();
    bool estaVacia();

    string imprimirRutaBus();
    Ruta* busqueda(string);
    bool busquedaTransporte(string);
    string disponibilidadRutas();
    void guardar(string,string);

};

