#pragma once
#include "TrajeAbstracto.h"
#include "MangaLarga.h"
#include "DeVestir.h"
#include "Ejecutivo.h"
class TrajeEjecutivo :
    public TrajeAbstracto{

private:
	double preciosCamisa[2][4] = {{325,280,150,125},
							  {375,315,175,165}};

	double preciosPant[2][4] = {{300,250,125,100},
								{500,450,260,200}};

	double preciosCalz[2][4] = {{400,350,250,175},
								{450,400,325,200}};
public:
	
	TrajeEjecutivo(string cod, string medida);
	~TrajeEjecutivo();
	
	string toString(string tipo);
	void setPreciosRopa();
	
	CamisaAbstracta* crearCamisa(string color, bool opc = false);
	PantalonAbstracto* crearPantalon(string color, bool opc = false);
	ZapatoAbstracto* crearZapatos(string color, bool opc = false);

};

