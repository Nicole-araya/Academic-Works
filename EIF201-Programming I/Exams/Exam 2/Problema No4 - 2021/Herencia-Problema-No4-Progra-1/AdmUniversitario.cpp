#include"AdmUniversitario.h"

AdmUniversitario::AdmUniversitario(string ced, string nom, int NH, string titul, int AL)
: Trabajador(ced,nom,NH), titulo(titul),aniosLaborales(AL){
}

AdmUniversitario::~AdmUniversitario() {
}

string AdmUniversitario::toString() {
		stringstream s;
		s << "-------------ADMINISTRADOR UNIVERSITARIO-----------------" << endl;
		s << Trabajador::toString();
		s << "Titulo: " << titulo << endl;
		s << "Anios Laborales: " << aniosLaborales << endl;

		return s.str();
}