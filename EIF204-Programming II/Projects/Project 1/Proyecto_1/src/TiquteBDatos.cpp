#include "TiquteBDatos.h"

void TiquteBDatos::guardar(ofstream& salida, Tiquete* t)
{
	salida << t->getIdentificador() << "\t";
	salida << t->getRuta()->getRuta() << "\t";
	salida << t->getPlaca() << "\n";
}
