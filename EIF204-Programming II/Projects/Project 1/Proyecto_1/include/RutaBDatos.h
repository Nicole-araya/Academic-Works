#pragma once
#include "Ruta.h"
#include <fstream>
using namespace std;
class RutaBDatos
{
public:

	static void guardarRuta(ofstream&,Ruta*);
	static void guardarRTransporte(ofstream&, Ruta*);

};

