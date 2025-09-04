#pragma once
#include "TrajeAbstracto.h"
#include "ConCuadros.h"
#include "Jeans.h"
#include "Bota.h"
class TrajeTrabajo :
    public TrajeAbstracto{

private:
	double preciosCamisa[2][4] = {{250,200,150,100},
							  {300,250,175,150}};

	double preciosPant[2][4] = {{150,100,50,25},
								{200,150,75,90}};

	double preciosCalz[2][4] = {{220,200,150,75},
								{250,225,175,90}};

public:

	TrajeTrabajo(string cod, string medida);
	~TrajeTrabajo();

	string toString(string tipo);
	void setPreciosRopa();

	CamisaAbstracta* crearCamisa(string color, bool opc = false);
	PantalonAbstracto* crearPantalon(string color, bool opc = false);
	ZapatoAbstracto* crearZapatos(string color, bool opc = false);
};

