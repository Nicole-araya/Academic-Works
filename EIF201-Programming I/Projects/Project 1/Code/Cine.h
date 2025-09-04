#pragma once
#include "ColeccionPF.h"

int const tamPeliculas = 50;
int const tamFunciones = 50;

class Cine
{
private:

	int tamP;
	int tamF;

	ColeccionPF* coleccion;

public:

	Cine();
	~Cine();


	int calcularPrecioTiquete(int, int, string);
	void menuAdministrador();
	void menuUsuario(string*, string*);
	void menu();

};

