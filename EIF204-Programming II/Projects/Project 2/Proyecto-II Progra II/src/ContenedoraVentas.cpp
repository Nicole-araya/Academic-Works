#include "ContenedoraVentas.h"

ContenedoraVentas::~ContenedoraVentas()
{
	list<Venta*>::iterator it;
	for (it = ventas.begin(); it != ventas.end(); it++) {
		ventas.erase(it);
	}
}

void ContenedoraVentas::agregaVenta(Venta* venta){
	ventas.push_back(venta);
}

double ContenedoraVentas::ventasTotalSinGanancia()
{
	double suma = 0;
	list<Venta*>::iterator it = ventas.begin();
	for (it = ventas.begin(); it != ventas.end(); it++) {
		suma += (*it)->precioSinGanancias();
	}
	return suma;
}

double ContenedoraVentas::ventasTotalConGanancia()
{
	double suma = 0;
	list<Venta*>::iterator it = ventas.begin();
	for (it= ventas.begin(); it != ventas.end(); it++) {
		suma += (*it)->precioConGanancias();
	}
	return suma;
}

double ContenedoraVentas::ventasTotalNetas()
{
	double suma = 0;
	list<Venta*>::iterator it = ventas.begin();
	for (it = ventas.begin(); it != ventas.end(); it++) {
		suma += (*it)->gananciaNeta();
	}
	return suma;
}

Venta* ContenedoraVentas::trajeMasVendido()
{
	if (ventas.empty()) { return NULL; } //Si esta vacio

	int suma = 0;
	int varsuma = 0;
	Venta* venta = NULL; Venta* auxventa = NULL;
	list<Venta*>::iterator it = ventas.begin();
	list<Venta*>::iterator it2;

	for (it=ventas.begin(); it != ventas.end();it++) {

		if (varsuma < suma) { varsuma = suma; auxventa = venta; }  //Si algun traje tiene una suma igual va a dar el primero que agarre
		suma = 0;
		it2 = ventas.begin();

		for (it2 = ventas.begin(); it2 != ventas.end(); it2++) {

			if ((*it)->getTraje()->getCodigo() == (*it2)->getTraje()->getCodigo()) {

				suma += 1;

			}
		}
		venta = *it;
	}
	return auxventa;
}

string ContenedoraVentas::toString(){
	stringstream ss;
	list<Venta*>::iterator it = ventas.begin();
	for(it= ventas.begin(); it != ventas.end(); it++){
		ss<<(*it)->factura() << endl;

	}
	return ss.str();
}

void ContenedoraVentas::guardarDatos(string nom)
{
	ofstream salida(nom);
	list<Venta*>::iterator it = ventas.begin();
	for (it= ventas.begin(); it != ventas.end(); it++) {
		
		GuardarDatos::guardarVenta(salida, (*it));
	}
	salida.close();
}
