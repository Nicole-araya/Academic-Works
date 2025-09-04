#pragma once
#include "ArbolAVL.h"
#include "Archivo.h"
#include <iostream>
#include "Excepcion.h"
const int TAM_HEAP = 200;
class Menu
{
private:
	ArbolAVL<Cliente>* arbol;
	Heap<Cliente>* heap;
	

public:

	Menu();
	~Menu();
	void menu();

};

