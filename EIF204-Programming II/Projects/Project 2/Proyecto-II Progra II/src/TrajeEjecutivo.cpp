#include "TrajeEjecutivo.h"

TrajeEjecutivo::TrajeEjecutivo(string cod, string medida):TrajeAbstracto(cod, medida){

}

CamisaAbstracta* TrajeEjecutivo::crearCamisa(string color, bool lisa){
	opcCamisa = lisa;

		this->camisa = new MangaLarga("C" + this->codigo, preciosCamisa[opcCamisa][med], color, opcCamisa);
	return camisa;
}

PantalonAbstracto* TrajeEjecutivo::crearPantalon(string color, bool casi ){
	opcPantalon = casi;

		this->pantalon = new DeVestir("P" + this->codigo, preciosPant[opcPantalon][med], color, opcPantalon);
	return pantalon;
}

ZapatoAbstracto* TrajeEjecutivo::crearZapatos(string color, bool fino){
	opcCalzado = fino;

		this->calzado = new Ejecutivo("Z" + this->codigo, preciosCalz[opcCalzado][med], color, opcCalzado);
	return calzado;
}

TrajeEjecutivo::~TrajeEjecutivo(){}

string TrajeEjecutivo::toString(string tipo){
	stringstream ss;
	ss << TrajeAbstracto::toString("Ejecutivo") << endl;
	return ss.str();
}

void TrajeEjecutivo::setPreciosRopa(){
	this->camisa->setPrecio(preciosCamisa[opcCamisa][med]);
	this->pantalon->setPrecio(preciosPant[opcPantalon][med]);
	this->calzado->setPrecio(preciosCalz[opcCalzado][med]);
}
