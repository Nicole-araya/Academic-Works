#include "BusCar.h"

BusCar::BusCar()
{
	lr = new ListaRuta();
	lt = new ListaTiquete();
	lb = new ListaTransporte();
}

BusCar::~BusCar()
{
	delete lr, lt,lb;
}

void BusCar::menuPrincipal()
{
	int entra = 1; string archivoR = "ListaRuta.txt", archivoT="ListaBuses.txt", archivoTiq= "ListaTiquetes.txt", archivoRB="ListaRBus.txt";


	int opcion = 0;

	while (opcion != 4) {

		try {
			if (entra) {      //Si es la primera vez entrando 

				Archivo::crearArchivos(archivoR, archivoT,archivoRB);  // Abre los archivos y lo cierra, si no existiera los archivos los crea.

				                                                        //Carga los datos si hay, y los inserta en las listas
				Archivo::cargarDatosTransporte(lb,archivoT);      
				Archivo::cargarDatosRuta(lr,archivoR,lb);
				Archivo::cargarDatosRutaBuses(lr, archivoRB, lb);
				cout << "Cargando los Datos..." << endl << endl;

				entra = 0;
				system("pause");
				system("cls");
			}

		cout << " ------------ MENU ---------------" << endl;
		cout << " -----------------------------------" << endl;
		cout << " 1. Configuracion de la flota de transporte " << endl;
		cout << " 2. Reserva de Tiquetes " << endl;
		cout << " 3. Reportes " << endl;
		cout << " 4. Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;

		system("pause");
		system("cls");

			switch (opcion) {

			case 1:

				menuConfiguracion();

				system("pause");
				system("cls");

				break;

			case 2:

				reservaTiquete();

				system("pause");
				system("cls");

				break;

			case 3:

				menuReportes();

				system("pause");
				system("cls");

				break;

			case 4:

				lt->guardar(archivoTiq);
				lb->archivoGuarda(archivoT);
				lr->guardar(archivoR,archivoRB);

				cout << "Guardando..." << endl;
				system("pause");
				system("cls");

				cout << "CERRANDO PROGRAMA..." << endl << endl;

				system("pause");
				system("cls");

				break;
			default:

				cin.clear(); 
				throw opcion;

				system("pause");
				system("cls");

			}
			
		}
		catch (int num) {

			if(num!=true){  
				cin.ignore(); 
				cout << LetterOption::excepcion();
			}
			else {
					cout<< NotFound::excepcion();
			}
			system("pause");
			system("cls");
			}
		catch (Transporte* t) {

			if (t) {
				cout << Found::excepcion();
			}
			else {
				cout << NotFound::excepcion();
			}
			system("pause");
			system("cls");
		}
		catch (Ruta* r) {

			if (r) {
				cout << Found::excepcion();
			}
			else {
				cout << NotFound::excepcion();
			}
			system("pause");
			system("cls");
		}
		catch (Tiquete* t) {

			cout << NotAvaible::excepcion();
			system("pause");
			system("cls");
		}
		catch (fstream& f) {

			cout << Downloading::excepcion();
			f.close();
			system("pause");
			system("cls");
		}
		catch (bool x) {

			cout << Existence::excepcion();
			system("pause");
			system("cls");
		}

	}
}

void BusCar::menuConfiguracion()
{
	string nom, placa, codigo; bool existe;
	int opcion = 0, num,max;
	Ruta* r = NULL; Transporte* t = NULL;

	while (opcion != 7) {

		cout << " ------- MENU CONFIGURACION -------" << endl;
		cout << " -----------------------------------" << endl;
		cout << " 1. Tipos de Buses " << endl;
		cout << " 2. Rutas de viaje " << endl;
		cout << " 3. Agregar buses a una Ruta " << endl;
		cout << " 4. Restriccion Sanitaria " << endl;
		cout << " 5. Mostrar Buses " << endl;
		cout << " 6. Mostrar Rutas con Buses " << endl;
		cout << " 7. Regresar " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;


		system("pause");
		system("cls");

		switch (opcion) {

		case 1:

			cout << " Tipos de Buses " << endl;
			cout << "-------------------" << endl;
			cout << " Tipo de Bus: "; cin >> nom;
			cout << endl << " Cantidad max de pasajeros: "; cin >> num;
			cout << endl << " Placa: "; cin >> placa;

			t = lb->busqueda(placa);
			if (t != NULL) {           //si ya existe
				throw t; 

			}
			else {
				lb->agregar(new RestriccionTransporte(placa, nom, num));

				cout <<endl<< " Ingreso exitoso! " << endl;
			}

			system("pause");
			system("cls");

			break;

		case 2:

			cout << " Rutas de viaje " << endl;
			cout << "-------------------" << endl;
			cout << " Codigo de Ruta: "; cin >> codigo;
			cout << endl << " Nombre de la Ruta: "; cin.ignore(); getline(cin, nom);

			if (r=lr->busqueda(codigo)) {     //si ya existe

				throw r;
			}
			else {
				lr->agregar(new Ruta(codigo, nom));
				cout << endl << " Ingreso exitoso! " << endl;
			}

			system("pause");
			system("cls");

			break;

		case 3:

			cout << " Agregar buses a una Ruta " << endl;
			cout << "---------------------------" << endl;
			cout << " Codigo de Ruta: "; cin >> codigo;

			if (r = lr->busqueda(codigo)) {
				
				cout << endl << " Placa del bus: "; cin >> placa;
				t = r->getLista()->busqueda(placa);


				if (t  != NULL ) {     //si existe el bus en ruta 
					throw t;
				}
				if ( existe=lr->busquedaTransporte(placa)) {   // si ya esta en otra ruta
					throw existe;
				}
                                                       // De lo contrario,
					t = lb->busqueda(placa);        
					if (t == NULL) {        //Si no existe bus
						throw t;
					}
					else {                            //se puede insertar
						r->insertarTransporte(t);
						cout << endl << " Ingreso exitoso! " << endl;
					}
			}
			else {
				throw r;
			}

			system("pause");
			system("cls");

			break;

		case 4:

			cout << " Restriccion Sanitaria " << endl;
			cout << "------------------------" << endl;
			cout << " % Maximo de aforo: "; cin >> max;

			lb->restriccion(max);
			cout << lb->toString();

			system("pause");
			system("cls");

			break;

		case 5:

			cout << " Mostrar Buses  " << endl;
			cout << "----------------------" << endl;
			cout << lb->toString()<<endl;

			system("pause");
			system("cls");

			break;
		case 6:

				cout << "  Mostrar Rutas con Buses " << endl;
				cout << "----------------------------" << endl;
				cout << lr->imprimirRutaBus()<<endl; 


				system("pause");
				system("cls");

				break;

		case 7:

			cout << " Regresando..." << endl << endl;

			system("pause");
			system("cls");

			break;
		default:
			cin.clear();
			throw opcion;

			system("pause");
			system("cls");
		}
	}
}

void BusCar::reservaTiquete()
{
	Tiquete* tiq=NULL; Ruta* r=NULL;
	string id, cod,placa; int num;  int numC, numO,numT;

	cout << " -----------------------------" << endl;
	cout << " *** Reservar de Tiquetes *** " << endl;
	cout << " ------------------------------" << endl;

	cout << lr->toString();

	cout <<endl<<endl<< " Ingrese codigo de la ruta que desea reservar: "; cin >> cod;

		system("pause");
		system("cls");

	if (r=lr->busqueda(cod)) {   // apartir de aqui para crear tiquete

		numO = r->getLista()->contadorOcupados(); numC = r->getLista()->contarCapacidad();
		numT =  numC - numO;

		cout <<endl<< "RUTA: ";
		cout << r->toString() << endl << "Cantidad de asientos disponibles: " << numT << endl;
		cout << " ------------------------------" << endl;
		cout << endl<<" Cedula del cliente: "; cin >> id;
		cout << endl << "Cantidad de pasajeros: ";cin >> num;

		if (numO + num <= numC) {    //si hay espacio para la cantidad de personas que se quiere

			lt->agregar( tiq = new Tiquete(id, r, num));   //tiquete creado

			string aux="";
			while (num != 0) {    //Reservando los buses de la ruta

				num--;
				placa = tiq->Reservar();

				if (aux == "") { tiq->setPlaca(placa); }  //Si no hay placa todavia, se ingresera
				else {
					if (aux != placa) { tiq->setPlaca(placa + " " + tiq->getPlaca()); } // si llegara haber mas placas al reservar se insertan      
				}
				aux = placa;
			}

			system("pause");
			system("cls");

			cout << "**** TIQUETE  ******" << endl;
			cout << tiq->toString()<< "" << endl;
		}
		else {
			throw tiq;  //no hay espacio
		}
	}
	else {

		throw r;

		system("pause");
		system("cls");
	}
}

void BusCar::menuReportes()
{
	int opcion = 0;

	while (opcion != 3) {

		cout << " ---------- MENU REPORTES ----------" << endl;
		cout << " -----------------------------------" << endl;
		cout << " 1. Mostrar todos lo tiquetes emitidos " << endl;
		cout << " 2. Mostrar la disponibilidad de pasajeros por ruta de viaje " << endl;
		cout << " 3. Regresar " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;

		system("pause");
		system("cls");

		switch (opcion) {

		case 1:

			cout << " Mostrar todos lo tiquetes emitidos " << endl;
			cout << "----------------------------------------" << endl;

			cout << lt->toString() << endl;

			system("pause");
			system("cls");

			break;

		case 2:
			cout << " Mostrar la disponibilidad de pasajeros por ruta de viaje " << endl;
			cout << "------------------------------------------------------------" << endl;

			cout << lr->disponibilidadRutas() << endl;

			system("pause");
			system("cls");

			break;

		case 3:

			cout << " Regresando..." << endl << endl;

			system("pause");
			system("cls");

			break;

		default:
			cin.clear();
			throw opcion;

			system("pause");
			system("cls");


		}

	}
}
