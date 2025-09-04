#include "MangaLarga.h"

MangaLarga::MangaLarga(string cod, double prec, string color, bool lisa) : CamisaAbstracta(cod, prec, color){
	this->boolOpc=lisa;
	descripcion = "0) No lisa      \n1) Lisa\n";
}

MangaLarga::~MangaLarga()
{
}

string MangaLarga::toString(){
	stringstream s;
	if (boolOpc){
		s << "Camisa de manga larga lisa de color " << color << endl;
	}else{
		s << "Camisa de manga larga no lisa de color " << color << endl;
	}
	return s.str();
}
