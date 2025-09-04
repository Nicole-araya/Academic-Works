#include "NetPro.h"

NetPro::NetPro(){

	lista = new Lista<Ruta>();
	grapDijk=new Graph<char, double>(TAM);
	grapKrus = new GraphK<char, double>(TAM);

	//Datos para generar archivo
	lista->agregarFinal(new Ruta('A', 'B', 2,1, 1, 3));
	lista->agregarFinal(new Ruta('A', 'C', 3, 1, 1, 2));
	lista->agregarFinal(new Ruta('B', 'C', 1, 0, 2, 5));
	lista->agregarFinal(new Ruta('B', 'D', 2, 0, 1, 2));
	lista->agregarFinal(new Ruta('C', 'E', 0, 1, 0, 3));
	lista->agregarFinal(new Ruta('C', 'F', 0, 0, 0, 2));
	lista->agregarFinal(new Ruta('D', 'E', 2, 1, 0, 1));
	lista->agregarFinal(new Ruta('D', 'F', 3, 1, 0, 4));
	lista->agregarFinal(new Ruta('D', 'H', 2, 0, 0, 0));
	lista->agregarFinal(new Ruta('D', 'G', 0, 4, 1, 0));
	lista->agregarFinal(new Ruta('E', 'F', 0, 2, 0, 0));
	lista->agregarFinal(new Ruta('F', 'H', 1, 2, 0, 1));
	lista->agregarFinal(new Ruta('G', 'H', 3, 0, 0, 3));
	lista->agregarFinal(new Ruta('G', 'I', 0, 1, 0, 1));
	lista->agregarFinal(new Ruta('H', 'I', 1, 3, 2, 0));

	lista->guardar(NOM);
}


NetPro::~NetPro(){

	delete lista,grapDijk,grapKrus;
}


void NetPro::menu() {

	int opcion = 0; 
	while (opcion != 4) {

		system("cls");
		cout << " ------MENU PRINCIPAL---------" << endl;
		cout << " 1. Cargar datos automaticos " << endl;
		cout << " 2. Dijkstra" << endl;
		cout << " 3. Kruskal " << endl;
		cout << " 4. Salir " << endl;
		cout << "-------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;

		system("pause");
		system("cls");
		try {
			switch (opcion) {

			case 1:
				Archivo::cargarDatos(grapDijk, grapKrus, NOM);
				cout << "\nCargando datos automaticos...\n" << endl;
				system("pause");
				system("cls");
				cout << endl << lista->toString();  //muestro los datos del .txt
				cout << "\nDatos cargados...\n" << endl;   
				system("pause");
				break;

			case 2:
				cout << "*****Dijkstra******" << endl;
				grapDijk->shortestPath('A'); cout << endl;
				system("pause");
				break;

			case 3:
				cout << "*****Kruskal******" << endl;
				grapKrus->imprimir(); cout << endl;
				system("pause");

				break;

			case 4:

				cout << "Saliendo..." << endl;
				system("pause");
				break;

			default:

				cin.clear();
				throw opcion;
				system("pause");
				system("cls");

			}
		}
		catch (int num) {
			cin.ignore();
			cout << Excepcion::opcionIncorrecta();
			system("pause");
			system("cls");
		}
		catch (ifstream& a) {
			
			cout << Excepcion::errorArchivo();
			system("pause");
			system("cls");
		}
	}

}