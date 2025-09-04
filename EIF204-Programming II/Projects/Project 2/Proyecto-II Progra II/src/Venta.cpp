#include "Venta.h"

Venta::Venta(Cliente* client, TrajeAbstracto* traje, string fecha){
	this->cliente = client;
	this->traje = traje;
	this->fecha = fecha;

	if (cliente!=NULL) {
		this->precioEnvio = calcularPrecioE();
	}
	else { precioEnvio = 0; }
}

double Venta::calcularPrecioE(){
	//puede ser que se necesite todo en minusulas para evitar problemas
	for(int i = 0; i < 9; i++){
		if(cliente->getPais() == codigos[0][i] and cliente->getCiudad() == codigos[1][i]){
			return precios[i];
			break;

		} else if(cliente->getPais() == codigos[0][8]){    //Para Costa Rica porque no tiene ciudad
			return precios[8];
			break;
		}
	}
}

string Venta::factura(){

	double conIva = precioConGanancias() * IVA + precioConGanancias();

	stringstream ss;
	ss << "Fecha: " << fecha << endl;
	ss << "=================================" << endl;
	cliente ? ss << cliente->toString() : ss << "Cliente en Tienda Fisica" << endl;
	ss << "=================================" << endl;
	traje ? ss << traje->toString() : ss << "Traje personalizado" << endl;
	ss << "=================================" << endl;
	ss << "Precio base del traje : " << precioSinGanancias();
	ss << "\nPrecio del traje (+80%): " << precioConGanancias();
	ss << "\nPrecio con IVA: " << conIva;
	ss << "\nPrecio de envio: " << precioEnvio << endl;
	ss << ">>>Precio Total a pagar: " << conIva + precioEnvio << endl;
	
	return ss.str();
}

double Venta::precioSinGanancias()
{
	return traje->getPrecio();
}

double Venta::precioConGanancias()
{
	return traje->getPrecio() * porcentajeGanancia + traje->getPrecio();
}

double Venta::gananciaNeta()
{
	return precioSinGanancias() * porcentajeGanancia;
}

double Venta::getPrecioEnvio() { return precioEnvio; }
string Venta::getFecha() { return fecha; }
Cliente* Venta::getCliente() { return cliente; }
TrajeAbstracto* Venta::getTraje() { return traje; }
void Venta::setPrecioEnvio(double envio)
{
	precioEnvio = envio;
}