#pragma once
#include "ListaRuta.h"
#include "ListaTiquete.h"
#include "ListaTransporte.h"
#include "Excepcion.h"
#include "Archivo.h"
#include <fstream>

using namespace std;
class BusCar
{
private:
	ListaRuta* lr;
	ListaTiquete* lt;
	ListaTransporte* lb;

public:
	BusCar();
	~BusCar();
	void menuPrincipal();
	void menuConfiguracion();
	void reservaTiquete();
	void menuReportes();
};

