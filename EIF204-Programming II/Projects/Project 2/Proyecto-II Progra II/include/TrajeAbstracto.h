#pragma once
#include "CamisaAbstracta.h"
#include "PantalonAbstracto.h"
#include "ZapatoAbstracto.h"
#include <sstream>

class TrajeAbstracto{
protected:
	string codigo;
	double precio;
	string medida;

	//indice para los precios;
	int med;

	bool opcCamisa, opcPantalon, opcCalzado;
	CamisaAbstracta* camisa;
	PantalonAbstracto* pantalon;
	ZapatoAbstracto* calzado;

public:

	TrajeAbstracto(string cod,string medida);
	~TrajeAbstracto();

	void setPrecio(double precio);
	void setCodigo(string codigo);
	void setMedida(string medida);
	double getPrecio();
	string getCodigo();
	string getMedida();
	CamisaAbstracta* getCamisa();
	PantalonAbstracto* getPantalon();
	ZapatoAbstracto* getZapato();

	double calculaPrecio();
	void setOpcCamisa(bool opcCamisa);
	void setOpcPant(bool opcPant);
	void setOpcZapatos(bool opcCalz);
	virtual void setPreciosRopa() = 0;      //poner precios a las prendas
	virtual string toString(string tipo = "-");

	virtual CamisaAbstracta* crearCamisa(string color, bool opc=false)=0;
	virtual PantalonAbstracto* crearPantalon(string color, bool opc = false) = 0;
	virtual ZapatoAbstracto* crearZapatos(string color, bool opc = false) = 0;
};


