// EXAMEN CON LA PILA 15-09-2022
// Estudiantes: 
//               Nicole Araya Ballestero
//               Esteban Mojica Gonzalez


#include <iostream>
#include "Controlador.h"

int main(){
    
    Controlador* c = new Controlador();

    c->menuPrincipal();
    delete c;
}
