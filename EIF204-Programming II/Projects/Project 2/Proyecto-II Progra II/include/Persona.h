#pragma once
#include "Cliente.h"
class Persona: public Cliente
{
private:
	string nacionalidad;
public:
	
	Persona(string cedula, string nom, string correo, double pago, string ciudad, string pais, string nacionalidad);
	~Persona();
	string toString();
	string getNacionalidad();
	void actualizar(bool);
};

