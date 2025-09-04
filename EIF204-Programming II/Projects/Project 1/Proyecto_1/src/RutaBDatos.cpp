#include "RutaBDatos.h"

void RutaBDatos::guardarRuta(ofstream& salida, Ruta* r)
{
		salida << r->getIdentificador() << "\t";
		salida << r->getRuta() << "\n";

}

void RutaBDatos::guardarRTransporte(ofstream& salida, Ruta* r)
{
	salida << r->getIdentificador() << "\n";
	r->getLista()->datosGuardar(salida);
}

