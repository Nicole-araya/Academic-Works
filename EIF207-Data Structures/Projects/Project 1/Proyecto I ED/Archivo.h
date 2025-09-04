#pragma once
#include <fstream>
#include "ArbolAVL.h"
#include "Cliente.h"
#include <iostream>
#include <sstream>
using namespace std;
class Archivo
{
public:
	void static cargarDatos(ArbolAVL<Cliente>* arbol, string nom);
};

