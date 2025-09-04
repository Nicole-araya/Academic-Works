/* Estructuras de Datos - Proyecto #1
Estudiantes:
Nicole Araya Ballestero
Esteban Mojica Gonzalez*/
#include "Menu.h"
#include <iostream>

int main(){


    Menu* m = new Menu();
    m->menu();

    delete m;
}