#pragma once
#include <sstream>
#include <iostream>
using namespace std;
class CamisaAbstracta{
private:
	

protected:
	string codigo;
	double precio;
	string color;
	bool boolOpc;  // true con y false sin
	string descripcion;

public:
	CamisaAbstracta(string,double,string);
	double getPrecio();

	~CamisaAbstracta();
	void setPrecio(double precios);
	virtual string getdescripcion();
	string getCodigo();
	string getColor();
	bool getBoolOpc();

	void setBoolOpc(bool opc);
	virtual string toString() = 0;
};
