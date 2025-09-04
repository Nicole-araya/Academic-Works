#pragma once
#include "TrajeAbstracto.h"
#include "Cliente.h"
#include <string>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const double IVA = 0.15;
const double porcentajeGanancia = 0.80;

class Venta{
private:

	//esta sirve para saber de donde es el cliente;
	string codigos[2][9] = {{"EEUU","Francia","Italia","Brasil","Argentina","Canada","Inglaterra","EEUU","CR"},
						{"New York","Paris","Milan","Brasilia","Buenos Aires","Ontario","Londres","California","--"}};

	double precios[9] = {100,200,250,150,175,160,200,150,50};

	TrajeAbstracto* traje;
	string fecha;
	Cliente* cliente;
	double precioEnvio;

public:

	Venta(Cliente* cliente, TrajeAbstracto* traje, string fecha);
	double calcularPrecioE();
	string factura();

	void setPrecioEnvio(double);
	double getPrecioEnvio();
	string getFecha();
	Cliente* getCliente();
	TrajeAbstracto* getTraje();


	double precioSinGanancias();
	double precioConGanancias();
	double gananciaNeta();
};

