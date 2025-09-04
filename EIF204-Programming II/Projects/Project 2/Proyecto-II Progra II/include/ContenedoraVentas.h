#pragma once
#include <list>
#include "Venta.h"
#include "GuardarDatos.h"
#include <sstream>
class ContenedoraVentas{
private:
	list<Venta*> ventas;
public:
	~ContenedoraVentas();
	void agregaVenta(Venta* venta);
	double ventasTotalSinGanancia();
	double ventasTotalConGanancia();
	double ventasTotalNetas();

	Venta* trajeMasVendido();

	string toString();
	void guardarDatos(string nom);

};

