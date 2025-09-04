#pragma once
#include<iostream>
#include<sstream>
#include <fstream>

using namespace std;

class Avion
{
private:

	string codigo;
	string categoria;

	int** asiento;
	int tamannio;
	int cantidad;

public:
	Avion(string, string, int);
	~Avion();

	void setTamannio(int);
	void setCodigo(string);
	void setCategoria(string);
	string getCodigo();
	string getCategoria();
	int getTamannio();
	int getCantidad();

	int insertarAsiento();
	int asientosDisponibles();

	void guardar(ofstream&);

	string toStringAvion();
};

