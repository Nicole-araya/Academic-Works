#include "TrajeTrabajo.h"

TrajeTrabajo::TrajeTrabajo(string cod, string medida) :TrajeAbstracto(cod, medida){

}

TrajeTrabajo::~TrajeTrabajo()
{
}

string TrajeTrabajo::toString(string tipo){
	stringstream ss;
	ss << TrajeAbstracto::toString("Trabajo") << endl;
	return ss.str();
}

void TrajeTrabajo::setPreciosRopa(){
	this->camisa->setPrecio(preciosCamisa[opcCamisa][med]);
	this->pantalon->setPrecio(preciosPant[opcPantalon][med]);
	this->calzado->setPrecio(preciosCalz[opcCalzado][med]);
}

CamisaAbstracta* TrajeTrabajo::crearCamisa(string color, bool cuadroG){
	opcCamisa = cuadroG;

		this->camisa = new ConCuadros("C" + this->codigo, preciosCamisa[opcCamisa][med], color, opcCamisa);

		return camisa;
}

PantalonAbstracto* TrajeTrabajo::crearPantalon(string color, bool ajuste){
	opcPantalon = ajuste;

		this->pantalon = new Jeans("P" + this->codigo, preciosPant[opcPantalon][med], color, opcPantalon);

	return pantalon;
}

ZapatoAbstracto* TrajeTrabajo::crearZapatos(string color, bool alta){
	opcCalzado = alta;

		this->calzado = new Bota("Z" + this->codigo, preciosCalz[opcCalzado][med], color, opcCalzado);

	return calzado;
}
