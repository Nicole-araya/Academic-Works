#pragma once
#include "Funcion.h"

class ColeccionPF
{
private:
	int tamFunc;
	int canFunc;
	Funcion** funcion;

	int tamPeli;
	int canPeli;
	Pelicula** pelicula;

public:

	ColeccionPF(int,int);
	~ColeccionPF();

	void setTamFun(int);
	void setTamPeli(int);

	int getTamFun();
	int getTamPeli();
	int getCanFun();
	int getCanPeli();

	bool insertarPelicula(Pelicula*);
	bool insertarFuncion(Funcion*);
	void eliminarPelicula(int );
	void eliminarFuncion(string);
	void eliminarFuncionxPeli(int);
	bool funcionMaxDia(string);
	bool vectorVacioPeli();
	bool vectorVacioFuncion();
	bool disponibilidadSala(int, string);

	Funcion* buscarFuncionxGenero(string);
	Funcion* buscarFuncion(string);
	Funcion* buscarFuncionPosicion(int);
	Pelicula* buscarPeliPosicion(int);
	Funcion* buscarFuncionxPeli(int);

	string ImprimirPelicula();
	string ImprimirFuncionesxGenero(string);
	string ImprimirFuncion();
	string ImprimirFuncionxFecha(string);
};

