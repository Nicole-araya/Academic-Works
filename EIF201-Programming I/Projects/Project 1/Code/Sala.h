#pragma once
#include <iostream>
#include <sstream>
#include <dos.h>

#define ANSI_COLOR_GREEN "\x1b[32m";
#define ANSI_COLOR_RED "\x1b[31m";
#define ANSI_COLOR_RESET "\x1b[0m";

using namespace std;

const int maxFila = 6;
const int maxColumna = 10;

class Sala
{
private:

	string tipo;


	int fila;
	int columna;
	string ***asiento;



public:

	Sala(string);
	~Sala();

	void setTipo(string);

	string getTipo();
	int getFila();
	int getColumna();


	bool insertarEstadoAsiento(char,int, string*);
	void confirmacionEstadoAsiento( char, string*,string*);
	int contadorAsientoDisponibles();
	bool confirmacionCompra(char, int, char);

	int retornaNumeroFila(char);
	char retornaLetraFila(int);
	string toString();





};

