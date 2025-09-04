#pragma once
#include "Vacuna.h"
class Paciente
{
private:
	string nombre;
	string id;
	float	peso;
	float estatura;
	int  annioNacimiento;
	int genero;

	Vacuna* vacuna;

public:

	Paciente(string, string, float, float, int, int, Vacuna* =NULL );
	~Paciente();
	string getNombre();
	string getId();
	float	getPeso();
	int  getAnnioNacimiento();
	float getEstatura();
	char getGenero();
	Vacuna* getVacuna();
	void setVacuna(Vacuna*);

	void setNombre(string);
	void setId(string);
	void setPeso(float);
	void setAnnioNacimiento(int);
	void setEstatura(float);
	void setGenero(char);

	string toString();
};

