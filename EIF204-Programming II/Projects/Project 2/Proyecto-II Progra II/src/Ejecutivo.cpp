#include "Ejecutivo.h"

Ejecutivo::Ejecutivo(string cod, double prec, string color, bool fino) : ZapatoAbstracto(cod, prec, color){
	this->boolOpc = fino;
	descripcion = "0) No fino	\n1) Fino\n ";
}

Ejecutivo::~Ejecutivo()
{
}

string Ejecutivo::toString()
{
	stringstream s;
	if (boolOpc){
		s << "Ejecutivo fino de color " << color << endl;
	}else{
		s << "Ejecutivo no fino de color " << color << endl;
	}
	return s.str();
}
