#pragma once
#include "NodoVuelo.h"
class ListaVuelo
{
private:

	NodoVuelo* primero;
	NodoVuelo* actual;

public:

	ListaVuelo();
	~ListaVuelo();

	bool insertar(Vuelo*);
	bool listaVacia();
	bool compararHora(string,string, Avion*);       //Para que no exista un mismo Avion a una misma fecha y hora
	bool comparaSobrecargo(Vuelo*,Sobrecargo*,Sobrecargo*,Sobrecargo*); //Para que no exista sobrecargos repetidos a una misma fecha y hora en un Vuelo
	bool comparaCopilotoVuelo(Vuelo*, Piloto*, Piloto*);  //Para que no exista copilotos repetidos a una misma fecha y hora en un Vuelo
	bool comparaPilotoVuelo(string,string, Piloto*);  //Para que no exista pilotos repetidos a una misma fecha y hora en un Vuelo

	Vuelo* buscar(string);
	string mostrarVueloDetallado(string);
	string informacionVueloAsientos(string);

	string toStringListaVuelo();
};

