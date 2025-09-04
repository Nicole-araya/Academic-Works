#pragma once
#include "Paciente.h"

const int Maximo = 5000;

class Coleccion
{
private:
	
	Paciente** paciente;
	int cantidad;
	int tamanno;

public:

	Coleccion();
	~Coleccion();

	int getTamanno();
	int getCantidad();

	bool insertarPacientes(Paciente*);

	string VisualizarPacientes();
	Paciente* BuscarPaciente(string id);
	void VacunarPaciente(string , int , int ,
		string , string , string );
	string MostrasPacientesGenero();
	float PorcetajePacientesVACUNADOS();
	float PorcetajePacientesNOVACUNADOS();

	string PacientesCasaComercial(string);


};

