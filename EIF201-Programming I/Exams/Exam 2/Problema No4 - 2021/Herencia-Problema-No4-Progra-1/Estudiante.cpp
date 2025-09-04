#include"Estudiante.h"

Estudiante::Estudiante(string ced, string nom, string carr, int ed):Persona(ced,nom){

	carrera = carr;
	edad = ed;

}


Estudiante::~Estudiante(){
}


string Estudiante::toString() {
	stringstream s;
	s << "------------ESTUDIANTE--------------" << endl;
	s<< "   Cedula..." << cedula << endl;
	s<< "   Nombre..." << nombre << endl;
	s<< "   Carrera.." << edad << endl;
	s<< "   Edad....." << edad << " anios." << endl;
	return s.str();
}