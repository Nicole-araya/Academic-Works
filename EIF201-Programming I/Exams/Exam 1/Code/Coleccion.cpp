#include "Coleccion.h"

Coleccion::Coleccion(){

	tamanno = Maximo;
	cantidad = 0;

	paciente = new Paciente * [tamanno];

	for (int i = 0;i < tamanno;i++) {
		paciente[i] = NULL;
	}

}


Coleccion::~Coleccion() {

	for (int i = 0;i < tamanno;i++) {
		delete paciente[i];
	}
	delete[] paciente;
}

int Coleccion::getTamanno() {
	return tamanno;
}
int Coleccion::getCantidad() {
	return cantidad;
}

bool Coleccion::insertarPacientes(Paciente* p) {


		if (cantidad < tamanno) {

			paciente[cantidad++] = p;

			cout << "SE INSERTO EXITOSAMENTE" << endl;
			return true;
		}

		cout << "NO SE PUDO INSERTAR" << endl;
		return false;
	
}

string Coleccion::VisualizarPacientes() {
	stringstream s;

	for (int i = 0; i < cantidad;i++) {

		s <<"1. "<< paciente[i]->toString() << endl;

		if (paciente[i]->getVacuna() == NULL) {
			s << "No esta Vacunado" << endl;
		}
		else {
			s << "Esta vacunado" << endl;
		}


	}


	return s.str();
}


Paciente* Coleccion::BuscarPaciente(string id) {

	if (cantidad > 0) {

		for (int i = 0;i < cantidad;i++) {
			if (paciente[i]->getId() == id) {


				return paciente[i];
			}
		}
	}
	return NULL;
	
}

void Coleccion::VacunarPaciente(string id, int numLote,int numSerie,
string fechaVencimiento,string fechaAplicacion, string casaComercial ) {

	for (int i = 0;i < cantidad;i++) {

		if (paciente[i]->getId() == id) {

			paciente[i]->setVacuna(new Vacuna(numLote,numSerie,fechaVencimiento,fechaAplicacion,casaComercial));
			
			}
		}

	}
	


string Coleccion::MostrasPacientesGenero() {
	stringstream s;
	

	s << "  Lista de Mujeres" << endl;
	s << "----------------------" << endl;

	for (int i = 0;i < cantidad;i++) {
		if (paciente[i]->getGenero() == 1) {

			s << "ID: "<< paciente[i]->getId() << " Nombre: " << paciente[i]->getNombre() << endl;
		}
	}
	s << endl<<endl;
	s << "  Lista de Hombres" << endl;
	s << "----------------------" << endl;

	for (int i = 0;i < cantidad;i++) {
		if (paciente[i]->getGenero() == 2 ) {

			s << "ID: " << paciente[i]->getId() << " Nombre: " << paciente[i]->getNombre() << endl;
		}
	}



	return s.str();
}


float Coleccion::PorcetajePacientesVACUNADOS() {

	float cantidadVacunados = 0.0;

	for (int i = 0;i < cantidad;i++) {

		if (paciente[i]->getVacuna() != NULL) {

			cantidadVacunados++;
		}
	}


	return ((cantidadVacunados * 100) / cantidad);

}

float Coleccion::PorcetajePacientesNOVACUNADOS() {

	float cantidadNOVacunados = 0.0;

	for (int i = 0;i < cantidad;i++) {

		if (paciente[i]->getVacuna() == NULL) {

			cantidadNOVacunados++;
		}
	}


	return ((cantidadNOVacunados * 100) / cantidad);

}

string Coleccion::PacientesCasaComercial(string casa) {
	stringstream s;

	for (int i = 0;i < cantidad;i++) {
		if (paciente[i]->getVacuna() != NULL) {
			if (paciente[i]->getVacuna()->getCasaComercial() == casa) {

				s << "ID: " << paciente[i]->getId() << " Nombre: " << paciente[i]->getNombre() << endl;
			}
		}
	}

	return s.str();
}