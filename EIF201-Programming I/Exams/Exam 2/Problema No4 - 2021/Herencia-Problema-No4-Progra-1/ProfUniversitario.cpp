#include"ProfUniversitario.h"

ProfUniversitario::ProfUniversitario(string ced, string nom, int nH, bool prop, string GA)
:Trabajador(ced,nom,nH),propiedad(prop),gradoAcademico(GA){

}

ProfUniversitario::~ProfUniversitario(){
}


string ProfUniversitario::toString() {
	stringstream s;
	s << "-------------PROFESOR UNIVERSITARIO-----------------" << endl;
	s << Trabajador::toString();
	s<< "Propiedad: " << propiedad << endl;
	s << "Grado Academico: " << gradoAcademico << endl;

	return s.str();
}

