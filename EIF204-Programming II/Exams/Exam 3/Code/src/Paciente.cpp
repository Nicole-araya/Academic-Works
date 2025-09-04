#include "Paciente.h"

Paciente::Paciente(string idi, string nom, string tel, string corr, string sec) {
	id = idi;
	nombre = nom;
	telefono = tel;
	correo = corr;
	secuencia = sec;
}

Paciente::~Paciente() {
}

string Paciente::getId() { return id; }
string Paciente::getNombre() { return nombre; }
string Paciente::getTelefono() { return telefono; }
string Paciente::getCorreo() { return correo; }
string Paciente::getSecuencia() { return secuencia; }

string Paciente::toString() {
	stringstream s;
	s << "ID =" << id << "   Nombre = " << nombre << endl
		<< "Secuencia = " << secuencia << endl << endl;
	return s.str();
}

Paciente* Paciente::recuperaPaciente(ifstream& arch1) {

	string nom, ced, telf, corr, sec;

	if (!arch1.eof()) {

		getline(arch1, ced, ',');
		getline(arch1, nom, ',');
		getline(arch1, telf, ',');
		getline(arch1, corr, ',');
		getline(arch1, sec, '\n');

		if (!ced.empty() && !sec.empty())
		{
			return new Paciente(ced, nom, telf, corr, sec);

		}
	}
}