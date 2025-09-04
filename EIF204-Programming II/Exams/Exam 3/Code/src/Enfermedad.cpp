#include "Enfermedad.h"

Enfermedad::Enfermedad(string nE, string sE) {
	nombreEnferm = nE;
	secEnferm = sE;
}

Enfermedad::~Enfermedad() {
}

string Enfermedad::getNombEnfermedad() { return nombreEnferm; }
string Enfermedad::getSecEnfermedad() { return secEnferm; }

string Enfermedad::toString() {
	stringstream s;
	s << "Nombre de la enfermedad =" << nombreEnferm << endl
		<< "Secuencia de la enfermedad = " << secEnferm << endl << endl;
	return s.str();
}

Enfermedad* Enfermedad::recuperaEnfermedad(istream& arch1) {
	string nom, sec;

	if (!arch1.eof()) {

		getline(arch1, nom, ',');
		getline(arch1,sec, '\n');

		if (!nom.empty() && !sec.empty())
		{
			return new Enfermedad(nom, sec);
			
		}
	}

}