#include "ConCuadros.h"

ConCuadros::ConCuadros(string cod, double prec, string color, bool tam): CamisaAbstracta(cod,prec,color){
	boolOpc = tam;
	descripcion = "0) Cuadros pequenios      \n1) Cuadros grandes\n ";
}

ConCuadros::~ConCuadros()
{
}

string ConCuadros::toString(){
	stringstream s;
	if (boolOpc) {
		s << "Camisa de cuadros grandes de color " << color << endl;
	}else{
		s << "Camisa de cuadros pequenios de color " << color << endl;
	}
	return s.str();
}
