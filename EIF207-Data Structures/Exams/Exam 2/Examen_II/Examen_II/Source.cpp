/*
Estructuras de Datos - Examen II
Estudiante: Nicole Araya Ballestero
*/

#include "NetPro.h"
#include <iostream>
int main() {
	
	NetPro* menu = new NetPro();
	menu->menu();

	delete menu;
	return 0;
}