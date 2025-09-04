#pragma once
#include"Pila.h"
#include "Excepcion.h"
const int canDISCO = 4;
class Controlador{

private:
    Pila<float> torre1;
    Pila<float> torre2;
    Pila<float> torre3;
    int movimientos;
    int disco;
    int minMovimienos;

public:
    Controlador();
    void insertarTorre1();
    void imprimirSolucion(int disco, int t1, int t2, int t3, bool flag=true);
    bool comparaTop(Pila<float>& n1,Pila<float>& n2);
    void menuJuego();
    void menuPrincipal();
  
};

