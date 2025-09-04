#pragma once
#include <sstream>
#include <iostream>
using namespace std;
class ZapatoAbstracto
{
protected:
	string codigo;
	double precio;
	string color;

	bool boolOpc;
	string descripcion;

public:
	ZapatoAbstracto(string,double,string);
	double getPrecio();
	~ZapatoAbstracto();

	void setPrecio(double precios);

	virtual string getdescripcion();
	string getCodigo();
	string getColor();
	bool getBoolOpc();

	void setOpc(bool opc);
	virtual string toString() = 0;
};

