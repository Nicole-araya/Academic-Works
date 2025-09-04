#include "RutaReservar.h"

Transporte* RutaReservar::reservar(Ruta* r)
{ 
	return r->getLista()->reservar();
}

int RutaReservar::porcentajedisponibilidad(Ruta* r)
{
	int x=r->getLista()->contarCapacidad();
	int y=r->getLista()->contadorOcupados();

	if (x == 0 && y == 0) { return 0; }    //si esta vacio 

	int resultado = abs(((y * 100) / x) - 100);
	return resultado;
}

