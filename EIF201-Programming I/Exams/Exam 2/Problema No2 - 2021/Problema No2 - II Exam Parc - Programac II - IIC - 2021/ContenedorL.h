#pragma once
#include"Nodo.h"

class ContenedorL {
   private:

      Nodo* primero;   
      Nodo* actual;

   public:
    ContenedorL();
    virtual ~ContenedorL();
    bool estaVacia();
    void ingresarProducto(Producto*);
    bool  compararaListasIguales(ContenedorL*);
    string toString();
    
};

