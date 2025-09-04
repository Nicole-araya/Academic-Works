#include "ContPacientes.h"

ContPacientes::ContPacientes() {
	can = 0;
	tam = 100;
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContPacientes::~ContPacientes() {
	for (int i = 0; i < can; i++)
		delete vec[i];
}

int ContPacientes::getCantidad() {
	return can;
}

Paciente* ContPacientes::obtPacienteEnPos(int i) {
	return vec[i];
}

bool ContPacientes::ingresaPaciente(Paciente* pac) {
	if (can < tam) {
		vec[can++] = pac;
		return true;
	}
	else
		return false;
}

void ContPacientes::recuperaPacientes(ifstream& arch1) {
	while (!arch1.eof()) {

		ingresaPaciente(Paciente::recuperaPaciente(arch1));
	}
}

void ContPacientes::limpiaContenedor() {
	for (int i = 0; i < can; i++)
		delete vec[i];
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
	can = 0;
}

string ContPacientes::toString() {
	stringstream s;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}