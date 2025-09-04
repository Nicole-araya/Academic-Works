#pragma once
#include <sstream>
#include <iostream>
using namespace std;
class PantalonAbstracto
{
protected:
	string codigo;
	double precio;
	string color;

	bool boolOpc;
	string descripcion;

public:
	PantalonAbstracto(string, double, string);
	double getPrecio();
	~PantalonAbstracto();

	void setPrecio(double precios);
	virtual string getdescripcion();
	string getCodigo();
	string getColor();
	bool getBoolOpc();
	void setBoolOpc(bool opc);
	virtual string toString() = 0;
};

