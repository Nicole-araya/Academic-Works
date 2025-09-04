#include"Ruta.h"

string Ruta::getDestino( int cod){
	
	if (cod) {

		return "Puntarenas";
	}

	return "";
}

double Ruta::getCostoPasaje(int cod){
	
	if (cod) {

		return 7500.0;
	}
	return 0;
}

double Ruta::tiempoDeRuta(int cod){
	
	if (cod) {

		return 2.0;
	}
	return 0;

}