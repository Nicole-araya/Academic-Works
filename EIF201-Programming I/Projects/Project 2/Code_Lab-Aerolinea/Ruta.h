#pragma once
#include<iostream>
#include<sstream>
#include <fstream>
using namespace std;

class Ruta
{
private:
	string codigo;
	string lugarOrigen;
	string lugarDestino;
	string duracion;
	int cantidadEscalas;
	double valorPasajeDolar;

public:
	
	Ruta(string, string, string, string, int, double);
	~Ruta();

	void setCodigo(string);
	void setLugarOrigen(string);
	void setLugardestino(string);
	void setDuracion(string);
	void setCantidadEscalas(int);
	void setValorPasajeDolar(double);
	string getCodigo();
	string getLugarOrigen();
	string getLugardestino();
	string getDuracion();
	int getCantidadEscalas();
	double getValorPasajeDolar();

	void guardar(ofstream&);

	string toStringRuta();
};

