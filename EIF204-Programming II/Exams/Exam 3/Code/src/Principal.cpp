
#include<iostream>
#include<sstream>
#include <windows.h>
#include "InterfazUsuario.h"
#include "RepAnalisis1.h"
#include "RepAnalisis2.h"
#include "RepAnalisis3.h"
using namespace std;

//-----------------------------------------------------------------------
// Nombre del Estudiante:Nicole Araya Ballestero
// ID 4 0250 0623
//_______________________________________________________________________

int main() {
	int op = 0;
	AplicacionADN* Co = new AplicacionADN;

	do {
		op = InterfazUsuario::menu();
		system("cls");

		switch (op) {

		case 1:  InterfazUsuario::ventanaCargarPacientes(Co); Co->verPacientesEnPantalla();   break;
		   case 2:  InterfazUsuario::ventanaCargaEnfermedades(Co); Co->verEnfermedadesEnPantalla();  break;
		   case 3:  Co->reporte(new RepAnalisis1());   		    break;
		   case 4:  Co->reporte(new RepAnalisis2());		    break;
		   case 5:  Co->reporte(new RepAnalisis3());		    break;
		   case 6:  cout << "M U C H A S   G R A C I A S" << endl;  break;
		   default: cout << " ERROR: Digite una opcion correcta." << endl;
		};  // fin del switch.
		system("pause");
	} while (op != 6);

	delete Co;
	return 0;
}
