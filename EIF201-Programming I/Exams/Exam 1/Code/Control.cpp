#include "Control.h"

Control::Control() {

	c = new Coleccion();
}

Control::~Control() {

	delete c;
}

void Control::menu() {


	int opcion = 0; int salir = 0; int entrada = 0;

	while (salir != 1) {

		cout << " ---------------------- " << endl;
		cout << "   BIENVENIDO USUARIO   " << endl;
		cout << " ---------------------- " << endl;

		cout << "1- Ingresar paciente" << endl;
		cout << "2- Mostrar todos los pacientes" << endl;
		cout << "3- Buscar paciente especifico" << endl;
		cout << "4- Vacunar paciente" << endl;
		cout << "5- Lista pacientes vacunados (por genero)" << endl;
		cout << "6- Porcentajes de vacunacion" << endl;
		cout << "7- Vacunados por casa comercial" << endl;
		cout << "8- Salir" << endl;
		cout << " ---------------------- " << endl;
		cout << " Digite la opcion a realizar: " << endl; cin >> opcion;

		system("pause");
		system("cls");

		string id = ""; string nombre = ""; string fechV = ""; string fechA = ""; string CasaC = "";    float peso = 0.0; float altura = 0.0;
		int annio = 0; int numLote = 0; int numSerie = 0;      int genero = ' ';

		switch (opcion) {

		case 1:
			cout << endl << endl;
			cout << "  Registro del paciente " << endl << endl;
			cout << "----------------------------" << endl;
			cout << " Digite el ID: " << endl; cin >> id;
			cout << " Digite el nombre: " << endl; cin >> nombre;
			cout << " Digite el annio de nacimiento: " << endl; cin >> annio;
			cout << " Digite el peso: " << endl; cin >> peso;
			cout << " Digite la altura: " << endl; cin >> altura;
			cout << " Digite el genero: (Digite '1' para femenino o '2' para marculino)" << endl; cin >> genero;


			c->insertarPacientes(new Paciente(nombre, id, peso, altura, annio, genero));

			system("pause");
			system("cls");
			break;

		case 2:
			cout << " -------------------------- " << endl;
			cout << "  Pacientes Registrados " << endl << endl;
			cout << "----------------------------" << endl;

			cout << c->VisualizarPacientes() << endl;



			system("pause");
			system("cls");
			break;
		case 3:
			cout << " ------------------------------------ " << endl;
			cout << "  Consulta de Paciente Especifico " << endl << endl;
			cout << "-------------------------------------" << endl;
			cout << "Digite el Id del paciente a buscar: " << endl; cin >> id;

			if (c->BuscarPaciente(id) != NULL) {

				cout << c->BuscarPaciente(id)->toString();
			}
			else {
				cout << "NO EXISTE EL ID DE ESE PACIENTE" << endl;
			}

			system("pause");
			system("cls");
			break;
		case 4:
			cout << " ------------------------------------ " << endl;
			cout << "		 VACUNACION " << endl << endl;
			cout << "-------------------------------------" << endl;
			cout << "Digite el Id del paciente a buscar: " << endl; cin >> id;
			
				if (c->BuscarPaciente(id) != NULL) {

					cout << " Digite el numero de lote: " << endl; cin >> numLote;
					cout << " Digite el numero de serie: " << endl; cin >> numSerie;
					cout << " Digite la fecha de vencimiento: " << endl; cin >> fechV;
					cout << " Digite la fecha de aplicacion: " << endl; cin >> fechA;
					cout << " Digite la casa comercial: " << endl; cin >> CasaC;



					 c->VacunarPaciente(id, numLote, numSerie, fechV, fechA, CasaC);
				}
				else {
					cout << "NO EXISTE EL ID DE PACIENTE" << endl;
				}

				

			system("pause");
			system("cls");

			break;
		case 5:
			cout << " -------------------------- " << endl;
			cout << " Mostras Lista de Vehiculos " << endl;
			cout << " -------------------------- " << endl;
			cout << c->MostrasPacientesGenero();

			system("pause");
			system("cls");

			break;
		case 6:

			cout << " -------------------------- " << endl;
			cout << "  Porcentaje de Vacunacion" << endl << endl;
			cout << "-----------------------------" << endl;

			cout << " De un 100% hay un " << c->PorcetajePacientesVACUNADOS() << "% de pacientes vacunados" << endl;

			cout << " De un 100% hay un " << c->PorcetajePacientesNOVACUNADOS() << "% de pacientes no vacunados" << endl;



			system("pause");
			system("cls");

			break;

		case 7:
			cout << "-----------------------------" << endl;
			cout << "Vacunacion por Casa Comercial" << endl << endl;
			cout << "-----------------------------" << endl;
			cout << " Digite la Casa Comercial a buscar: " << endl; cin >> CasaC;

			cout<< c->PacientesCasaComercial(CasaC); 

			system("pause");
			system("cls");

			break;

		case 8:

			cout << " -------------------------- " << endl;
			cout << "    ¿Desea salir del menu?    " << endl;
			cout << "    1. Si      2. No        " << endl;
			cout << " -------------------------- " << endl;
			cout << " Digite el numero: " << endl; cin >> entrada;

			if (entrada == 1) {
				salir = 1;
			}

			system("pause");
			system("cls");

			break;

		default:

			cout << "No existe esa opcion, ingrese el numero de las opciones exitentes" << endl;
			system("pause");
			system("cls");
			break;
		}


	}

}