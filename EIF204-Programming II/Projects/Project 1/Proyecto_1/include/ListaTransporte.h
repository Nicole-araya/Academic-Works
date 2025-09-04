#pragma once
#include <fstream>
#include"NodoTransporte.h"
#include "TransporteBDatos.h"

using namespace std;

class ListaTransporte
{
private:
    NodoTransporte* primero;
    NodoTransporte* actual;
public:

    ListaTransporte();
    ~ListaTransporte();
    void agregar(Transporte*);
    string toString();
    bool estaVacia();
  
    Transporte* busqueda(string);

    void restriccion(int);

    int contarCapacidad(); //suma todos los asientos de los buses
    int contadorOcupados(); //suma de asientos ocupados entre todos los buses

    Transporte* reservar();

    void archivoGuarda(string);

    void datosGuardar(ofstream&);
};

