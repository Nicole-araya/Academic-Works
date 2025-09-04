#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Persona
{
protected:

	string nombre;
	string id;

public:

	Persona(string, string);
	~Persona();

	void setNombre(string);
	void setID(string);
	string getNombre();
	string getID();

	virtual string toString();

};

