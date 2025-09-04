#include "Pantaloneta.h"

Pantaloneta::Pantaloneta(string cod, double prec, string color, bool est) : PantalonAbstracto(cod, prec, color){
	boolOpc = est;
	descripcion = "0) No estampada       \n1) Estampada\n ";
}

Pantaloneta::~Pantaloneta()
{
}

string Pantaloneta::toString(){
	stringstream s;
	if (boolOpc){
		s << "Pantalon estampado de color " << color << endl;
	}else{
		s << "Pantalon no estampado de color " << color << endl;
	}
	return s.str();
}
