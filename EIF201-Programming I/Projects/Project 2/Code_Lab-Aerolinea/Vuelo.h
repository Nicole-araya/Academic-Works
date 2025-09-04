#pragma once
#include "ListaPasajero.h"
#include "Avion.h"
#include "Ruta.h"
#include "Piloto.h"
#include "Sobrecargo.h"
#include <string>

const int MaxTam =3;

class Vuelo
{
private:
	string codigo;
	string fechaSalida;
	string horaSalida;
	string horaLlegada;
	string nombreAeropuertoSalida;
	string nombreAeropuertoLlegada;
	Ruta* ruta;
	Piloto* piloto;
	Piloto* copiloto;
	Avion* avion;
	Sobrecargo* s1;
	Sobrecargo* s2;
	Sobrecargo* s3;

	ListaPasajero* pasajero;
		
public:

	Vuelo(string, string, string, string, string, string, Ruta*, Piloto*, Avion*);
	~Vuelo();

	void setCodigo(int);
	void setFechaSalida(string);
	void setHoraSalida(string);
	void setHoraLlegada(string);
	void setNombreAeropuertoSalida(string);
	void setNombreAeropuertoLlegada(string);
	void setRuta(Ruta*);
	void setPiloto(Piloto*);
	void setAvion(Avion*);
	void setCopiloto(Piloto*);
	void setSobrecargo1(Sobrecargo*);
	void setSobrecargo2(Sobrecargo*);
	void setSobrecargo3(Sobrecargo*);

	string getCodigo();
	string getFechaSalida();
	string getHoraSalida();
	string getHoraLlegada();
	string getNombreAeropuertoSalida();
	string getNombreAeropuertoLlegada();
	Ruta* getRuta();
	Piloto* getPiloto();
	Piloto* getCopiloto();
	Avion* getAvion();
	Sobrecargo* getSobrecargo1();
	Sobrecargo* getSobrecargo2();
	Sobrecargo* getSobrecargo3();


	bool insertarPasajero(Pasajero*);
	bool compararSobrecargo(string );
	bool comparaSobrecargoVuelo(Sobrecargo*, Sobrecargo*, Sobrecargo*);
	bool compararCopilotoVuelo(Piloto*, Piloto*);
	bool compararPilotoVuelo(Piloto*);
	bool disponibilidad();

	string MostrarTripulacion();
	string capacidadYlistaPasajero();
	string mostrarPasajeros();
	string MostrarVueloSimple();
	string MostrarVueloDetallado();

};

