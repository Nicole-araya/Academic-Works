#pragma once
//#include"Pila.h"
#include "Excepcion.h"
#include "Cola.h"
const int canDISCO = 4;
class Controlador{

private:
    Cola<float> torre1;
    Cola<float> torre2;
    Cola<float> torre3;
    int movimientos;
    int disco;
    int minMovimienos;

public:
    Controlador();
    void insertarTorre1();
    void imprimirSolucion(int disco, int t1, int t2, int t3, bool flag=true);
    bool comparaTop(Cola<float>& n1,Cola<float>& n2);
    void menuJuego();
    void menuPrincipal();
  
};

