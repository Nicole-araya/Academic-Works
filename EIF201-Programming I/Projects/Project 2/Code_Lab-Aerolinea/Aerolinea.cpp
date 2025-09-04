#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
	la = new ListaAvion();
	lr = new ListaRuta();
	lv = new ListaVuelo();
	lp = new ListaPiloto();
	ls = new ListaSobrecargo();
}

Aerolinea::~Aerolinea()
{
	delete la, lr, lv, lp, ls;
}

void Aerolinea::menuAdministrador() {
	int opcion = 0;

	while (opcion != 6) {

		cout << " ------------ MENU ADMINISTRADOR ---------------" << endl;
		cout << " 1. Ingresar Avion" << endl;
		cout << " 2. Ingresar Rutas" << endl;
		cout << " 3. Contratacion de Personas" << endl;
		cout << " 4. Administracion de Vuelos" << endl;
		cout << " 5. Guardar datos" << endl;
		cout << " 6. Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: " << endl;
		cin >> opcion;


		system("pause");
		system("cls");

		string cod, cat, origen, destino, duracion, nom, id, correo, titulo, telf;
		int tam, num, edad, grado;
		double precio;
		char sexo;

		string archivoA = "ListaAvion.txt"; string archivoR = "ListaRuta.txt";string archivoP = "ListaPiloto.txt";string archivoS = "ListaSobrecargo.txt";

		switch (opcion) {

		case 1:
		
			cout << "------- Ingreso de Avion --------" << endl;
			cout << "Ingrese el codigo del Avion: " << endl; cin >> cod;
			
			if (la->buscar(cod) == NULL) {

				cout << "Ingrese la categoria del Avion: " << endl; cin >> cat;
				cout << "Ingrese el tamannio de capacidad del Avion: " << endl; cin >> tam;
				system("pause");
				system("cls");

				if (la->insertar(new Avion(cod, cat, tam)) == true) {
					cout << "Ingreso Exito..." << endl;
				}
				else cout << "NO se pudo insertar..." << endl;
			
			}
			else cout << "Ya existe este codigo..." << endl;


			system("pause");
			system("cls");

			break;

		case 2:
			cout << "------- Ingreso de Ruta -------" << endl;
			cout << "Ingrese el codigo de la ruta: " << endl; cin >> cod;

			if (lr->buscar(cod) == NULL) {

				cout << "Ingrese el Origen: " << endl; cin.ignore(); getline(cin, origen);
				cout << "Ingrese el Destino: " << endl; cin.ignore(); getline(cin, destino);
				cout << "Duracion de la ruta: " << endl; cin.ignore(); getline(cin, duracion);
				cout << "Numero de Escalas: " << endl; cin >> tam;
				cout << "Costo del pasaje: " << char(36) << endl; cin >> precio;
				system("pause");
				system("cls");

				if (lr->insertar(new Ruta(cod, origen, destino, duracion, tam, precio)) == true) {
					cout << "Ingreso Exito..." << endl;
				}
				else cout << "NO se pudo insertar..." << endl;


			}
			else cout << "Ya existe este codigo..." << endl;


			system("pause");
			system("cls");

			break;

		case 3:

			cout << "------- Contratacion de Personas ------" << endl;
			cout << " 1. Ingresar Piloto" << endl;
			cout << " 2. Ingresar Sobrecargo" << endl;
			cout << " 3. Volver al Menu Administrador" << endl<<endl;
			cout << " Ingrese la opcion a realizar: " << endl; cin >> num;
			system("pause");
			system("cls");

			if (num == 1) {

				cout << "------- Ingreso de Piloto ------" << endl;
				cout << "Ingrese el ID: " << endl; cin >> id;

				if (lp->buscar(id) == NULL) {

					cout << "Ingrese el nombre: " << endl; cin.ignore(); getline(cin, nom);
					cout << "Ingrese la edad: " << endl; cin >> edad;
					cout << "Ingrese el correo: " << endl; cin.ignore(); getline(cin, correo);
					cout << "Ingrese el sexo (M de masculino o F de femenino) : " << endl;  cin >> sexo;


					if (lp->insertar(new Piloto(nom, id, edad, correo, sexo)) == true) {
						cout << "Ingreso Exito..." << endl;
					}
					else cout << "NO se pudo insertar..." << endl;
				}
				else cout << "Ya existe este ID..." << endl;

			}
			else {

				if (num == 2) {
					cout << "------- Ingreso de Sobrecargo ------" << endl;
					cout << "Ingrese el ID: " << endl; cin >> id;

					if (ls->buscar(id) == NULL) {

						cout << "Ingrese el nombre: " << endl; cin.ignore(); getline(cin, nom);
						cout << "Ingrese la edad: " << endl; cin >> edad;
						cout << "Ingrese el titulo: " << endl; cin>> titulo;
						cout << "Ingrese el numero de telefono: " << endl;  cin>>telf;
						cout << "Ingrese el grado: " << endl; cin >> grado;
			

						if (ls->insertar(new Sobrecargo(nom, id, edad, titulo, telf, grado)) == true) {
							cout << "Ingreso Exito..." << endl;
						}
						else cout << "NO se pudo insertar..." << endl;
					}
					else cout << "Ya existe este ID..." << endl;
					
				}else cout << "Volviendo al menu..." << endl;
			}
			system("pause");
			system("cls");

			break;

		case 4:

			menuAdminitradorVuelo();

			system("pause");
			system("cls");

			break;

		case 5:

			cout << "------- GUARDANDO DATOS ------" << endl;

			la->guardarAvion(archivoA);
			lr->guardarRuta(archivoR);
			lp->guardarPiloto(archivoP);
			ls->guardarSobrecargo(archivoS);

			cout << "Digite enter..." << endl << endl;

			system("pause");
			system("cls");

			break;

		case 6:

			cout << "CERRANDO SESION..." << endl << endl;

			system("pause");
			system("cls");

			break;

		default:
			cout << "NO COINCIDE CON NINGUNA OPCION" << endl;

			system("pause");
			system("cls");


		}

	}
}

void Aerolinea::menuAdminitradorVuelo() {

	int opcion = 0, num;
	string cod, fecS, horaS, horaL, nomS, nomL, codR, codA, idP, idC, idA1,idA2,idA3;
	Ruta* ruta = NULL; Avion* avion = NULL; Piloto* piloto = NULL; Vuelo* vuelo = NULL; Sobrecargo* sobrecargo = NULL; Piloto* copiloto = NULL;
	bool res = true;

	while (opcion != 6) {

		cout << " ---- ADMINISTRAR VUELOS ----" << endl;
		cout << " 1. Ingresar vuelo" << endl;
		cout << " 2. Lista General de Vuelos" << endl;
		cout << " 3. Detalle de Vuelo Especifico" << endl;
		cout << " 4. Capacidad y Lista de Pasajeros por Vuelo" << endl;
		cout << " 5. Tripulacion por Vuelo" << endl;
		cout << " 6.Regresar al Menu Administrador" << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: " << endl;
		cin >> opcion;


		system("pause");
		system("cls");


		switch (opcion) {

		case 1:

			if (lr->listaVacia() || la->listaVacia() || lp->listaVacia()) cout << "NO SE PUEDE INGRESAR HAY LISTAS VACIAS" << endl;
			else {
				cout << "----- Ingreso de Vuelo ------" << endl;
				cout << "Ingrese el codigo del Vuelo: " << endl; cin >> cod;

				if (lv->buscar(cod) == NULL) {

					cout << "Ingrese la fecha de Salida: " << endl; cin>>fecS;
					cout << "Ingrese la hora de Salida: " << endl; cin >> horaS;
					cout << "Ingrese la hora de Llegada: " << endl; cin >> horaL;
					cout << "Ingrese el Aeropuerto de Salida: " << endl; cin.ignore();  getline(cin, nomS);
					cout << "Ingrese el Aeropuerto de Llegada: " << endl; cin.ignore(); getline(cin, nomL); 

					cout << "Cargando..." << endl;
					system("pause");
					system("cls");

					cout << "*** LISTA DE AVIONES" << endl << endl;
					cout << la->toStringListaAvion();
					cout << endl << endl << "Ingrese el codigo del Avion: " << endl; cin >> codA;

					avion = la->buscar(codA);
					while (avion == NULL) {    //Se repetira hasta ingrese correctamente un codigo
						cout << "NO Existe ese Codigo... Ingrese otra vez.." << endl << endl;
						system("pause");
						system("cls");

						cout << "*** LISTA DE AVIONES" << endl << endl;
						cout << la->toStringListaAvion() << endl;;
						cout << "Ingrese el codigo del Avion: " << endl; cin >> codA;
						avion = la->buscar(codA);
					}

					if (lv->compararHora(fecS, horaS, avion)) {  //SI EXISTE UN AVION, FECHA Y HORA DE SALIDA IGUAL, SE SALDRA.. 
						                                         //para que ingrese de nuevo los datos, por si quiere cambiar todo lo ingresado.
						cout << "ERROR, ya existe un avion con la misma fecha y hora de salida" << endl;
						cout << "Saliendo.." << endl;
						system("pause");
						system("cls");
					}
					else {

						cout << "Cargando..." << endl;
						system("pause");
						system("cls");
						//---------------------------------------------------------------------------------

						cout << "*** LISTA DE RUTAS" << endl << endl;
						cout << lr->toStringListaRuta();
						cout << endl << endl << "Ingrese el codigo de la Ruta: " << endl; cin >> codR;

						ruta = lr->buscar(codR);

						while (ruta == NULL) {    //Se repetira hasta ingrese correctamente un codigo
							cout << "NO Existe ese Codigo... Ingrese otra vez.." << endl << endl;
							system("pause");
							system("cls");

							cout << "*** LISTA DE RUTAS" << endl << endl;
							cout << lr->toStringListaRuta() << endl;;
							cout << "Ingrese el codigo de la Ruta: " << endl; cin >> codR;
							ruta = lr->buscar(codR);
						}
						cout << "Cargando..." << endl;
						system("pause");
						system("cls");
						//---------------------------------------------------------------------------------

						cout << "*** LISTA DE PILOTOS" << endl << endl;
						cout << lp->toStringListaPiloto();
						cout << endl << endl << "Ingrese el ID del Piloto: " << endl; cin >> idP;

						piloto = lp->buscar(idP);
						while (piloto == NULL || lv->comparaPilotoVuelo(fecS, horaS, piloto) == true) {    //Se repetira hasta ingrese correctamente un codigo
							
							if (piloto == NULL) {
								cout << "NO Existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE PILOTOS" << endl << endl;
								cout << lp->toStringListaPiloto() << endl;
								cout << "Ingrese el ID del Piloto: " << endl; cin >> idP;
								piloto = lp->buscar(idP);
							}
							if (lv->comparaPilotoVuelo(fecS, horaS, piloto)) { //Se repetira hasta que el horario de piloto no choque con otro vuelo
								cout << "Ese ID tiene otro vuelo que choca con este horario... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE PILOTOS" << endl << endl;
								cout << lp->toStringListaPiloto() << endl;
								cout << "Ingrese el ID del Piloto: " << endl; cin >> idP;
								piloto = lp->buscar(idP);
							}
						}

						cout << "Cargando..." << endl;
						system("pause");
						system("cls");

						cout << "Creando vuelo..." << endl;
						lv->insertar(new Vuelo(cod, fecS, horaS, horaL, nomS, nomL, ruta, piloto, avion));
						cout << "Ingreso Exitoso" << endl;
						system("pause");
						system("cls");

					}
				}
				else cout << "Ya existe este Codigo..." << endl;
			}

			system("pause");
			system("cls");

			break;

		case 2:
			cout << "----- Lista General de Vuelos ------" << endl;
			cout << lv->toStringListaVuelo()<<endl;

			
			system("pause");
			system("cls");

			break;
		case 3:
			cout << "---- Detalle de Vuelo Especifico -----" << endl;
			cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

			vuelo = lv->buscar(cod);
			if (vuelo != NULL) {

				cout << lv->mostrarVueloDetallado(cod);
			}
			else cout << "NO existe el codigo del vuelo ingresado" << endl;

			system("pause");
			system("cls");

			break;
		case 4:
			cout << "---- Capacidad y Lista de Pasajeros por Vuelo -----" << endl;
			cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

			vuelo = lv->buscar(cod);
			if (vuelo != NULL) {

				cout << lv->informacionVueloAsientos(cod);

			}
			else cout << "NO existe el codigo del vuelo ingresado" << endl;

			system("pause");
			system("cls");

			break;
		case 5:
			cout << "---- Tripulacion por Vuelo -----" << endl;
			cout << " 1. Ingreso de la Tripulacion al vuelo" << endl;
			cout << " 2. Mostrar Tripulacion por vuelo" << endl;
			cout << " 3. Regresar..." << endl;
			cout << " Ingrese la opcion a realizar: " << endl;
			cin >> num;

			cout << "Cargando..." << endl << endl;
			system("pause");
			system("cls");

			if (num == 1) {
				if (ls->listaVacia() == false && lp->listaVacia() == false) {
					cout << "---- Ingresar Tripulación a un vuelo -----" << endl;
					cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

					vuelo = lv->buscar(cod);
					if (vuelo != NULL && vuelo->getCopiloto() == NULL) {   //Si el vuelo existe y no esta lleno ya su tripulacion que entre

						cout << "VUELO ENCONTRADO!!" << endl;
						system("pause");
						system("cls");

						cout << "*** LISTA DE PILOTOS para ser Copiloto" << endl << endl;
						cout << lp->toStringListaPiloto() << endl << endl;
						cout << "(No repita persona...)" << endl;
						cout << "Digite el ID del Copiloto: "; cin >> idC;
						copiloto = lp->buscar(idC);

						while ( lp->buscar(idC) == NULL || vuelo->getPiloto() == copiloto || lv->comparaCopilotoVuelo(vuelo, copiloto, copiloto) != false ) {

							copiloto = lp->buscar(idC);

							if (copiloto == NULL) {      //Se repetira hasta ingrese correctamente un id existente
								cout << "NO existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE PILOTOS para ser Copiloto" << endl << endl;
								cout << lp->toStringListaPiloto() << endl;
								cout << "Ingrese el ID del Copiloto: " << endl; cin >> idC;
							}
							if (vuelo->getPiloto() == copiloto) {    //Se repetira hasta ingrese correctamente un id diferente
								cout << "Ese ID ya se ingreso para piloto... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE PILOTOS para ser Copiloto" << endl << endl;
								cout << lp->toStringListaPiloto() << endl;
								cout << "Ingrese el ID del Copiloto: " << endl; cin >> idC;
							}
							if (lv->comparaCopilotoVuelo(vuelo, copiloto, copiloto) != false) { //si retorna true se repetira hasta que copiloto no choque horario con otro vuelo
								cout << "Ese ID choca su horario con otro vuelo... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE PILOTOS para ser Copiloto" << endl << endl;
								cout << lp->toStringListaPiloto() << endl;
								cout << "Ingrese el ID del Copiloto: " << endl; cin >> idC;
	
							}

							copiloto = lp->buscar(idC);
						}

						vuelo->setCopiloto(copiloto);
						cout << "Cargando..." << endl;
						system("pause");
						system("cls");
						//---------------------------------------------------------------------------

						cout << "*** LISTA DE SOBRECARGO" << endl << endl;
						cout << ls->toStringListaSobrecargo() << endl;
						cout << endl << "Digite el ID del sobrecargo #1: "; cin >> idA1;
						sobrecargo = ls->buscar(idA1);

						while (sobrecargo == NULL || lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) == true ) {  
							
							if (sobrecargo == NULL) {                                                   //Se repetira hasta ingrese correctamente un id existente
								cout << "NO existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #1: "; cin >> idA1;
								sobrecargo = ls->buscar(idA1);
							}
							if (lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) == true) {       //si retorna true se repetira hasta que sobrecargo no choque horario con otro vuelo
								cout << "Ese ID choca su horario con otro vuelo... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #1: "; cin >> idA1;
								sobrecargo = ls->buscar(idA1);
							}
						}

						vuelo->setSobrecargo1(sobrecargo);
						cout << "Cargando..." << endl;
						system("pause");
						system("cls");
						//---------------------------------------------------------------------------

						cout << "*** LISTA DE SOBRECARGO" << endl << endl;
						cout << ls->toStringListaSobrecargo() << endl;
						cout << "(No repita id de sobrecargo...)" << endl;
						cout << endl << "Digite el ID del sobrecargo #2: "; cin >> idA2;

						sobrecargo = ls->buscar(idA2);
						while (sobrecargo == NULL || vuelo->getSobrecargo1()->getID() == idA2 || lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) == true) {   
							                                                                        
							if (sobrecargo == NULL) {                                           //Se repetira hasta ingrese correctamente un id existente
								cout << "NO existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #2: "; cin >> idA2;
								sobrecargo = ls->buscar(idA2);
							}

							if (vuelo->getSobrecargo1()->getID() == idA2) {                      //Se repetira hasta ingrese correctamente un id diferente a los existentes
								cout << "Ya existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #2: "; cin >> idA2;
								sobrecargo = ls->buscar(idA2);
							}

							if (lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) == true) { //si retorna true se repetira hasta que sobrecargo no choque horario con otro vuelo
								cout << "Ese ID choca su horario con otro vuelo... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #2: "; cin >> idA2;
								sobrecargo = ls->buscar(idA2);
							}
						}

						vuelo->setSobrecargo2(sobrecargo);
						cout << "Cargando..." << endl;
						system("pause");
						system("cls");

						//---------------------------------------------------------------------------
						cout << "*** LISTA DE SOBRECARGO" << endl << endl;
						cout << ls->toStringListaSobrecargo() << endl;
						cout << "(No repita id de sobrecargo...)" << endl;
						cout << endl << "Digite el ID del sobrecargo #3: "; cin >> idA3;

						sobrecargo = ls->buscar(idA3);
						res = vuelo->compararSobrecargo(idA3);

						while (ls->buscar(idA3) == NULL || res == true || lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) == true) {
							
							sobrecargo = ls->buscar(idA3);

							if (sobrecargo == NULL) {                                      //Se repetira hasta ingrese correctamente un id existente
								cout << "NO existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #3: "; cin >> idA3;

							}

							if (res == true) {  //Se repetira hasta ingrese correctamente un id diferente a los existentes
								cout << "Ya existe ese ID... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #3: "; cin >> idA3;
						
							}

							if (lv->comparaSobrecargo(vuelo, sobrecargo, sobrecargo, sobrecargo) != false) { //si retorna true se repetira hasta que sobrecargo no choque horario con otro vuelo
								cout << "Ese ID choca su horario con otro vuelo... Ingrese otra vez.." << endl << endl;
								system("pause");
								system("cls");

								cout << "*** LISTA DE SOBRECARGO" << endl << endl;
								cout << ls->toStringListaSobrecargo() << endl;
								cout << endl << "Digite el ID del sobrecargo #3: "; cin >> idA3;
							}

							res = vuelo->compararSobrecargo(idA3);
							sobrecargo = ls->buscar(idA3);
						}

						vuelo->setSobrecargo3(sobrecargo);
						cout << "Cargando..." << endl;
						system("pause");
						system("cls");

						cout << "Ingreso Exitoso!!" << endl << endl;
						system("pause");
						system("cls");
					}
					else if (vuelo == NULL) cout << "NO existe el codigo..." << endl;
					else if (vuelo->getCopiloto() != NULL) cout << "Ya tiene Tripulacion Registrada" << endl;

				}
				else  cout << "Hay listas Vacias..." << endl; 

			}
			if (num == 2) {

				cout << "----- Mostrar Tripulacion del vuelo -----" << endl;
				cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

				vuelo = lv->buscar(cod);
				if (vuelo != NULL) {

					cout << "Vuelo Encontrado!!" << endl << endl;
					cout << vuelo->MostrarTripulacion();

				}
				else cout << "NO existe el codigo del vuelo ingresado" << endl;
				system("pause");
				system("cls");
			}
			if (num == 3) {
				
				cout << "Regresando..." << endl << endl;
				
			}
			system("pause");
			system("cls");

			break;

		case 6:

			cout << "Volviendo al menu..." << endl << endl;

			system("pause");
			system("cls");

			break;

		default:
			cout << "NO COINCIDE CON NINGUNA OPCION" << endl;

			system("pause");
			system("cls");

		}
	}
}


void Aerolinea::menuCliente() {
	
	int opcion = 0;
	string cod, nom, id;
	Vuelo* vuelo = NULL; Pasajero* pasajero = NULL;

	while (opcion != 4) {

		cout << " ------------ MENU ---------------" << endl;
		cout << " 1. Mostar Lista General de Vuelos" << endl;
		cout << " 2. Detalle de Vuelo Especifico" << endl;
		cout << " 3. Venta de Boleto de Vuelo" << endl;
		cout << " 4.Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: " << endl;
		cin >> opcion;


		system("pause");
		system("cls");


		switch (opcion) {

		case 1:
			
			cout << "----- Lista General de Vuelos ------" << endl;
			cout << lv->toStringListaVuelo() << endl;

			system("pause");
			system("cls");

			break;

		case 2:
			cout << "---- Detalle de Vuelo Especifico -----" << endl;
			cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

			vuelo = lv->buscar(cod);
			cout << "Cargando..." << endl << endl;
			system("pause");
			system("cls");

			if (vuelo != NULL) {

				cout << lv->mostrarVueloDetallado(cod);
			}
			else cout << "NO existe el codigo del vuelo ingresado" << endl;
			system("pause");
			system("cls");

			break;

		case 3:
			cout << "----- Venta de Boleto ------" << endl;
			cout << "Ingrese el codigo del Vuelo: "; cin >> cod; cout << endl;

			vuelo = lv->buscar(cod);
	
			cout << "Cargando..." << endl << endl;
			system("pause");
			system("cls");

				if (vuelo != NULL) {    //Si encuentra vuelo entra

					if (vuelo->disponibilidad() == true) {     //Si hay disponibilidad de Asientos entra

						cout << "Vuelo Encontrado!!" << endl << endl;
						cout << lv->mostrarVueloDetallado(cod) << endl;

						cout << "Ingrese el nombre del pasajero: "; cin.ignore(); getline(cin, nom);
						cout << endl << "Ingrese su ID: "; cin >> id;

						pasajero = new Pasajero(nom, id);

						if (vuelo->insertarPasajero(pasajero)) {   //Si se inserta pasajero, se muestra el asiento que se elijio al azar

							cout << "Cargando..." << endl << endl;
							system("pause");
							system("cls");

							cout << "Compra Exitosa!!" << endl << endl;
							cout << "Se le ha asigando el asiento " << pasajero->getNumAsiento() << endl << endl;
						}
						else cout << "NO se pudo insertar.." << endl;
					}
					else cout << "NO hay Disponibilidad..." << endl;
				}
				else cout << "NO existe el codigo del vuelo ingresado" << endl;
			


			system("pause");
			system("cls");

			break;

		case 4:

			cout << "CERRANDO SESION..." << endl << endl;

			system("pause");
			system("cls");

			break;
		default:
			cout << "NO COINCIDE CON NINGUNA OPCION" << endl;

			system("pause");
			system("cls");


		}
	}

}



void Aerolinea::menu() {
	int entra = 1;
	int opcion = 0;
	string usuario, contra;
	string archivoA = "ListaAvion.txt"; string archivoR = "ListaRuta.txt";string archivoP = "ListaPiloto.txt";string archivoS = "ListaSobrecargo.txt";

	while (opcion != 3) {

		cout << " ------------ MENU ---------------" << endl;
		cout << " 1. Entrar como Administrador" << endl;
		cout << " 2. Entrar como Cliente" << endl;
		cout << " 3. Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: " << endl;
		cin >> opcion;

		system("pause");
		system("cls");

		switch (opcion) {

		case 1: 
			cout << " -------- MENU ADMINISTRADOR ---------------" << endl<<endl;

			cout << "* Nombre de Usuario: "; cin >> usuario;
			cout << endl << "* Contrase" << char(164) << "a: "; cin >> contra;
			cout << endl << endl;
			system("pause");
			system("cls");

			if (ArchivosAerolinea::verificarUsuarioAdmi(usuario, contra) == true) {  // Si puso la contra y usuario correcto entra
				 
				if (entra) {      //Si es la primera vez entrando al menu administrador que entre

					 // Abre los archivos y lo cierra, si no existiera los archivos los crea.
					ofstream fAux;
					fAux.open(archivoA, ios::out | ios::app);
					fAux.close();
					ofstream fAux2;
					fAux2.open(archivoR, ios::out | ios::app);
					fAux2.close();
					ofstream fAux3;
					fAux3.open(archivoP, ios::out | ios::app);
					fAux3.close();
					ofstream fAux4;
					fAux4.open(archivoS, ios::out | ios::app);
					fAux4.close();

					cout << "Cargando los Datos..." << endl << endl;

					ArchivosAerolinea::cargarDatos(la, lr, lp, ls);    //Carga los datos si hay, y los inserta en las listas

					entra = 0;
				}
				system("pause");
				system("cls");

				menuAdministrador();
		
			}
			else {

				cout << "Usuario o contrase" << char(164) << "a incorrecta..." << endl;
				system("pause");
				system("cls");
			}

			system("pause");
			system("cls");

			break;

		case 2:

			menuCliente();
			system("pause");
			system("cls");

			break;

		case 3:

			cout << "CERRANDO PROGRAMA..." << endl << endl;

			system("pause");
			system("cls");

			break;

		default:
			cout << "NO COINCIDE CON NINGUNA OPCION" << endl;

			system("pause");
			system("cls");


		}

	}

}