#include"Producto.h"

Producto::Producto(string nom, double pre) :nombreP(nom), precioP(pre){
}

Producto::~Producto() {}



string Producto::getNombreP() { 
	return nombreP; }

double Producto::getPrecioP() { 
	return precioP; }



string Producto::toString() {
	stringstream s;
	s << "    Nombre del producto..." << nombreP <<"'\t' Precio = " << precioP << endl;
	return s.str();
}

bool Producto::esIgualA(Producto& pro2) {
	
	if (pro2.getNombreP() == nombreP && pro2.getPrecioP() == precioP) {

		return true;
	}
	else {
		return false;
	}

}
