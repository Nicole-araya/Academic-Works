#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Contacto
{
private:
	string nombre;
	int edad;
	string telefono;
	string direccion;

public:

	Contacto(string,int,string,string);
	~Contacto();

	void setNombre(string);
	void setEdad(int);
	void setTel(string);
	void setDirec(string);

	string getNombre();
	int getEdad();
	string getTel();
	string getDirec();
};

