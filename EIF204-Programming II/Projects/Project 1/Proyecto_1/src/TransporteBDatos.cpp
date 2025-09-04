#include "TransporteBDatos.h"

void TransporteBDatos::guardar(ofstream& salida, RestriccionTransporte* t)
{
	salida << t->getNombre() << "\t";
	salida << t->getIdentificador() << "\t";
	salida << t->getNumAsientos() << "\t";
	salida << t->getPorcentaje() << '\n';

}

