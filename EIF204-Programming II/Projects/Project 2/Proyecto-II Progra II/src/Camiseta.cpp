#include "Camiseta.h"

Camiseta::Camiseta(string cod, double prec, string color, bool cuello) : CamisaAbstracta(cod, prec, color){
	boolOpc = cuello;

	descripcion = "0) Cuello en U       \n1) Cuello V\n ";  
}

Camiseta::~Camiseta()
{
}

string Camiseta::toString(){
	stringstream s;
	if (boolOpc) {
		s << "Camiseta de cuello en V de color " << color << endl;
	}else{
		s << "Camiseta de cuello en U de color " << color << endl;
	}
	return s.str();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                  