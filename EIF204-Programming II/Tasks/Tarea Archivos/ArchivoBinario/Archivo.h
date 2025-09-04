#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Archivo
{
private:
	string nombre;

public:
	Archivo(string);
	~Archivo();

	void setNombre(string);
	string getNombre();

};

