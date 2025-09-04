#include "Tenni.h"

Tenni::Tenni(string cod, double prec, string color, bool adida) : ZapatoAbstracto(cod, prec, color){
	boolOpc = adida;
	descripcion = "0)No adidas     \n1) Adidas\n ";
}

Tenni::~Tenni()
{
}

string Tenni::toString(){
	stringstream s;
	if (boolOpc) {
		s << "Tennis de Adidas de color " << color << endl;
	}else{
		s << "Tennis no Adidas de color " << color << endl;
	}
	return s.str();
}
