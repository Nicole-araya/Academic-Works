#pragma once
#include "TrajeAbstracto.h"
#include "Venta.h"
#include "Persona.h"
#include "Empresa.h"
#include <fstream>

class GuardarDatos
{
public:

	static void guardarPartesdeRopa(ofstream& salida,CamisaAbstracta* ca, PantalonAbstracto* panta, ZapatoAbstracto* zap);
	static void guardarTraje(ofstream& salida, TrajeAbstracto* traje);
	static void guardarSubscriptor(ofstream& salida, Cliente* subs);
	static void guardarVenta(ofstream& salida, Venta* venta);
};


