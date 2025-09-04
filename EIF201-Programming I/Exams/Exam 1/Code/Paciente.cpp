#include "Paciente.h"

Paciente::Paciente(string n, string i, float p, float e, int a, int g, Vacuna* v) {
	nombre = n;
	id = i;
	peso = p;
	estatura = e;
	annioNacimiento = a;
	genero = g;

	vacuna = v;
}

Paciente::~Paciente() {
	delete vacuna;
}

Vacuna* Paciente::getVacuna() {
	return vacuna;
}

void Paciente::setVacuna(Vacuna* v) {
	vacuna = v;
}
string Paciente::getNombre() {
	return nombre;
}
string Paciente::getId() {
	return id;
}
float	Paciente::getPeso() {
	return peso;
}
int  Paciente::getAnnioNacimiento() {
	return annioNacimiento;
}
float Paciente::getEstatura() {
	return estatura;
}
char Paciente::getGenero() {
	return genero;
}

void Paciente::setNombre(string n) {
	nombre = n;
}
void Paciente::setId(string i) {
	id = i;
}
void Paciente::setPeso(float p) {
	peso = p;
}
void Paciente::setAnnioNacimiento(int a) {
	annioNacimiento = a;
}
void Paciente::setEstatura(float e) {
	estatura = e;
}
void Paciente::setGenero(char g) {
	genero = g;
}


string Paciente::toString() {
	stringstream s;

	s << "---------------" << endl;
	s << "    PACIENTE    " << endl;
	s << "---------------" << endl;
	s << "ID: " << id << "  Nombre: " << nombre << endl;
	s << "Genero: " << genero << endl;
	s << "Annio de Nacimiento: " << annioNacimiento << endl;
	s << "Peso: " << peso << " Estatura: " << estatura << endl;



	return s.str();
}