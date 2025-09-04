#include "GuardarDatos.h"

void GuardarDatos::guardarPartesdeRopa(ofstream& salida, CamisaAbstracta* ca, PantalonAbstracto* panta, ZapatoAbstracto* zap)
{
	salida << ca->getColor() << "\t";
	salida << ca->getPrecio() << "\t";
	salida << ca->getBoolOpc() << "\t";

	salida << panta->getColor() << "\t";
	salida << panta->getPrecio() << "\t";
	salida << panta->getBoolOpc() << "\t";

	salida << zap->getColor() << "\t";
	salida << zap->getPrecio() << "\t";
	salida << zap->getBoolOpc() << "\n";
}

void GuardarDatos::guardarTraje(ofstream& salida, TrajeAbstracto* traje)
{
	salida << traje->getCodigo() << "\t";
	salida << traje->getPrecio() << "\t";
	salida << traje->getMedida() << "\t";
	guardarPartesdeRopa(salida, traje->getCamisa(), traje->getPantalon(), traje->getZapato());
}

void GuardarDatos::guardarSubscriptor(ofstream& salida, Cliente* subs)
{
	Persona* p = dynamic_cast<Persona*>(subs);
	Empresa* e = dynamic_cast<Empresa*>(subs);
	if (p) {
		salida << "P\t";
		salida << p->getNacionalidad() << "\t";
	}
	else {
		salida << "E\t";
		salida << e->getFrecuencia() << "\t";
	}
	salida << subs->getCedula() << "\t";
	salida << subs->getNombre() << "\t";
	salida << subs->getCorreo() << "\t";
	salida << subs->getPagoSubs() << "\t";
	salida << subs->getPais() << "\t";
	salida << subs->getCiudad() << "\n";
}



void GuardarDatos::guardarVenta(ofstream& salida, Venta* venta)
{
	salida << venta->getFecha() << "\t";
	salida << venta->getPrecioEnvio() << "\t";
	if (venta->getCliente() != NULL) {
		salida << venta->getCliente()->getCedula() << "\t";
	}
	else { salida << "000\t"; }
	salida << venta->getTraje()->getCodigo() << "\n";
}

