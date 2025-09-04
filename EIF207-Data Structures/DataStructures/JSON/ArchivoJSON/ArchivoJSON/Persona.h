#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class Persona
{
private:

	int id;
	string nombre;
	string direccion;

public:
	Persona(int=0, string="", string="");
	virtual ~Persona();

	int getID();
	string getNombre();
	string getDireccion();

	void setID(int);
	void setNombre(string);
	void setDireccion(string);

	string toString();

};

