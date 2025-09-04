#include"Trabajador.h"

Trabajador::Trabajador(string ced, string nom, int numHs):Persona(ced, nom){
	
	numHijos = numHs;
	can = 0;

	vecEdadesHijos = new int[numHijos];

	for (int i = 0; i < numHijos; i++)
	{

		vecEdadesHijos[i] = 0;

	}

}

Trabajador::~Trabajador(){
	if (vecEdadesHijos != NULL)
		delete vecEdadesHijos;
}

void Trabajador::llenarVecDeEdades(int edad) {

	if (can < numHijos) {

		vecEdadesHijos[can++] = edad;
	}
	
}


string Trabajador::toString() const {
	stringstream s;
	s << "------------TRABAJADOR--------------" << endl;
	s << "   Cedula..." << cedula << endl;
	s << "   Nombre..." << nombre << endl;
	s<< "   Cantidad de hijos:" << numHijos << endl;

	s<< "EDADES: " << endl;
		for (int i = 0; i < numHijos; i++)
		{

			s << vecEdadesHijos[i]<<endl;

		}


	return s.str();
}
