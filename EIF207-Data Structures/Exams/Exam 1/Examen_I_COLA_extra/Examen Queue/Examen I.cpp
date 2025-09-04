#include <iostream>
#include "Controlador.h"

int main(){
    
    Controlador* c = new Controlador();

    c->menuPrincipal();
    delete c;
}
