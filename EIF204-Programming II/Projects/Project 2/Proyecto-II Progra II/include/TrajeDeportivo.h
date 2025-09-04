#pragma once
#include "TrajeAbstracto.h"
#include "Camiseta.h"
#include "Tenni.h"
#include "Pantaloneta.h"
class TrajeDeportivo :
    public TrajeAbstracto{

private:
	double preciosCamisa[2][4] = {{150,100,75,50},
						  {200,150,125,75}};

	double preciosPant[2][4] = {{110,85,50,45},
								{150,130,80,75}};

	double preciosCalz[2][4] = {{225,200,150,75},
								{335,300,200,150}};
public:

	TrajeDeportivo(string cod, string medida);
	~TrajeDeportivo();
	string toString(string tipo);
	void setPreciosRopa();

	CamisaAbstracta* crearCamisa(string color, bool opc = false);
	PantalonAbstracto* crearPantalon(string color, bool opc = false);
	ZapatoAbstracto* crearZapatos(string color, bool opc = false);
};

