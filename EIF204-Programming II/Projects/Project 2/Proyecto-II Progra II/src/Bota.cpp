#include "Bota.h"

Bota::Bota(string cod, double prec, string color, bool tam) : ZapatoAbstracto(cod, prec, color){
	boolOpc = tam;
	descripcion = "0) Bota baja    \n1) Bota alta\n";
}

Bota::~Bota()
{
}

string Bota::toString(){
	stringstream s;
	if (boolOpc){
		s << "Bota alta de color " << color << endl;
	} else{
		s << "Bota baja de color " << color << endl;
	}
	return s.str();
}
