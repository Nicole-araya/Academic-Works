#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include "ListaAvion.h"
#include "ListaRuta.h"
#include "ListaVuelo.h"
#include "ListaPiloto.h"
#include "ListaSobrecargo.h"
#include <string>

using namespace std;
class ArchivosAerolinea
{
public:

	static bool verificarUsuarioAdmi(string, string);
	void static cargarDatos(ListaAvion*, ListaRuta*, ListaPiloto*, ListaSobrecargo*);

		
};

