#pragma once
#include "ListaTransporte.h"
#include "ListaRuta.h"
#include<fstream>

class Archivo
{
public:
	void static cargarDatosTransporte(ListaTransporte*,string);
	void static cargarDatosRuta(ListaRuta*,string, ListaTransporte*);
	void static cargarDatosRutaBuses(ListaRuta*, string, ListaTransporte*);
	void static crearArchivos(string, string, string);
};

