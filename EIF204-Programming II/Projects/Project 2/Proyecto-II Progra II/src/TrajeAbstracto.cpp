#include "TrajeAbstracto.h"

TrajeAbstracto::TrajeAbstracto(string cod, string medida)
{
	this->codigo = cod;
	camisa = NULL;
	pantalon = NULL;
	calzado = NULL;
	precio = 0;
	this->medida = medida;
	setMedida(medida);

	precio = 0;
}

double TrajeAbstracto::calculaPrecio(){
	double calculo = camisa->getPrecio() + pantalon->getPrecio() + calzado->getPrecio();

	setPrecio(calculo);
	return calculo;
}

void TrajeAbstracto::setOpcCamisa(bool opcCamisa){ this->opcCamisa = opcCamisa; }

void TrajeAbstracto::setOpcPant(bool opcPant){ this->opcPantalon = opcPant; }

void TrajeAbstracto::setOpcZapatos(bool opcCalz){ this->opcCalzado = opcCalz; }

string TrajeAbstracto::getMedida() { return medida; }

CamisaAbstracta* TrajeAbstracto::getCamisa() { return camisa; }
PantalonAbstracto* TrajeAbstracto::getPantalon() { return pantalon; }
ZapatoAbstracto* TrajeAbstracto::getZapato() { return calzado; }

string TrajeAbstracto::toString(string tipo){
	stringstream ss;
	ss << "Traje " << tipo <<" Medida "<<medida << endl;
	ss << "Codigo: " << codigo << endl;
	ss << "----------------------------" << endl;
	ss << "   Descripcion del traje    " << endl;
	ss << "----------------------------" << endl;
	ss<<camisa->toString();
	ss<<pantalon->toString();
	ss<<calzado->toString();
	return ss.str();
}

void TrajeAbstracto::setPrecio(double prec){
	this->precio = prec;
}

void TrajeAbstracto::setCodigo(string codigo){ this->codigo = codigo; }

void TrajeAbstracto::setMedida(string medida){ 
	if(medida == "l"){
		med = 0;
	} else if(medida == "m"){
		med = 1;
	} else if(medida == "s"){
		med = 2;
	} else{
		med = 3;
	}
	this->medida = medida; 
}

double TrajeAbstracto::getPrecio(){ return this->precio; }

string TrajeAbstracto::getCodigo(){ return this->codigo; }

TrajeAbstracto::~TrajeAbstracto(){}

