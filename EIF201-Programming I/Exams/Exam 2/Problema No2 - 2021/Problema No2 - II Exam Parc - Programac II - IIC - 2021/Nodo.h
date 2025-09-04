#pragma once
#include"Producto.h"

class Nodo {
    private:
	   Producto* producto; 
	   Nodo* sig;    
    public:
	   Nodo(Producto*, Nodo*);  
	   virtual ~Nodo();        
	   Producto* getProducto(); 
	   Nodo* getSiguiente();   
	   void setProducto(Producto*);  
	   void setSiguiente(Nodo*);    

	   string toString();
};
