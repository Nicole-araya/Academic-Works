#include "Jeans.h"

Jeans::Jeans(string cod, double prec, string color, bool ajus) : PantalonAbstracto(cod, prec, color){
	boolOpc = ajus;
	descripcion = "0) No ajustado     \n1) Ajustado\n ";
}

Jeans::~Jeans()
{
}

string Jeans::toString(){
	stringstream s;
	if (boolOpc) {
		s << "Pantalon ajustado de color " << color << endl;
	}else{
		s << "Pantalon no ajustado de color " << color << endl;
	}
	return s.str();
}
