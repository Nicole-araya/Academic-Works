#pragma once
#include "ArchivosAerolinea.h"
#include "ListaAvion.h"
#include "ListaRuta.h"
#include "ListaVuelo.h"
#include "ListaPiloto.h"
#include "ListaSobrecargo.h"
#include <string>

class Aerolinea
{
private:
	ListaAvion* la;
	ListaRuta* lr;
	ListaVuelo* lv;
	ListaPiloto* lp;
	ListaSobrecargo* ls;

public:
	Aerolinea();
	~Aerolinea();

	void menuAdministrador();
	void menuAdminitradorVuelo();
	void menuCliente();
	void menu();

};

