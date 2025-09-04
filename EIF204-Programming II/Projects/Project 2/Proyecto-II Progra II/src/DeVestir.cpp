#include "DeVestir.h"

DeVestir::DeVestir(string cod, double prec, string color, bool casi) : PantalonAbstracto(cod, prec, color){
	boolOpc = casi;
	descripcion = "0) No casimir     \n1) Casimir\n";
}

DeVestir::~DeVestir()
{
}

string DeVestir::toString(){
	stringstream s;
	if (boolOpc){
		s << "Pantalon casimir de color " << color << endl;
	}else{
		s << "Pantalon no casimir de color " << color << endl;
	}
	return s.str();
}
