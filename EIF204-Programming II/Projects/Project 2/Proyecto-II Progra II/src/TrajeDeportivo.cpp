#include "TrajeDeportivo.h"

TrajeDeportivo::TrajeDeportivo(string cod, string medida) :TrajeAbstracto(cod, medida){

}

TrajeDeportivo::~TrajeDeportivo()
{
}

string TrajeDeportivo::toString(string tipo){
	stringstream ss;
	ss<<TrajeAbstracto::toString("Deportivo")<<endl;
	return ss.str();
}

void TrajeDeportivo::setPreciosRopa(){
	this->camisa->setPrecio(preciosCamisa[opcCamisa][med]);
	this->pantalon->setPrecio(preciosPant[opcPantalon][med]);
	this->calzado->setPrecio(preciosCalz[opcCalzado][med]);
}

CamisaAbstracta* TrajeDeportivo::crearCamisa(string color, bool cuello){
	opcCamisa = cuello;
	
		this->camisa = new Camiseta("C" + this->codigo, preciosCamisa[opcCamisa][med], color, opcCamisa);
	return camisa;
}

PantalonAbstracto* TrajeDeportivo::crearPantalon(string color, bool estam){
	opcPantalon = estam;

		this->pantalon = new Pantaloneta("P" + this->codigo, preciosPant[opcPantalon][med], color, opcPantalon);
	return pantalon;
}

ZapatoAbstracto* TrajeDeportivo::crearZapatos(string color, bool adidas){
	opcCalzado = adidas;

		this->calzado = new Tenni("Z" + this->codigo, preciosCalz[opcCalzado][med], color, opcCalzado);
	return calzado;
}
