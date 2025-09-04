#include "Cine.h"
#include <string>

Cine::Cine() {

	coleccion = new ColeccionPF(tamPeliculas, tamFunciones);
}

Cine::~Cine() {

	delete coleccion;
}




int Cine::calcularPrecioTiquete(int canNinio, int canAdulto, string tiposala) {

	int precio = 0;
	int precioTotal = 0;

	if (tiposala == "Regular") {
	
		precio = canNinio * 3000;                       //si hay niños da un resultado, de lo contrario es cero.
		precioTotal = (canAdulto * 5000) + precio;       

		return precioTotal;
	}

	if (tiposala == "VIP") {

		precio = canNinio * 4500;                       //si hay niños da un resultado, de lo contrario es cero.
		precioTotal = (canAdulto * 6500) + precio;

		return precioTotal;
	}

	return 0;
}



void Cine::menuAdministrador() {


	Sala* s = new Sala("");
	Sala* s1 = new Sala("");

	int opcion = 0;

	while (opcion != 8) {

		cout << " ---------- ADMINTRADOR ---------------" << endl;
		cout << " 1. Crear Salas " << endl;
		cout << " 2. Crear Pelicula " << endl;
		cout << " 3. Crear Funcion " << endl;
		cout << " 4. Visualizar Peliculas " << endl;
		cout << " 5. Visualizar Funciones " << endl;
		cout << " 6. Eliminar Pelicula " << endl;
		cout << " 7. Eliminar Funcion " << endl;
		cout << " 8. Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la funcion a realizar: " << endl;
		cin >> opcion;

		system("pause");
		system("cls");

		string nombre = ""; string genero = "";string tipo = "";string dimension = "";string publico = "";
		string sipnosis;  string fecha = ""; string hora = "";

		int posicion = 0;  int numSala = 0;

		switch (opcion) {

		case 1:

			cout << "--------------------" << endl;
			cout << "  Crear Salas " << endl;
			cout << "--------------------" << endl;
			cout << "*** SOLO EXISTEN 2 SALAS" << endl;
			cout<<"Escribir 'VIP' en la primera y en la segunda 'Regular' " << endl<<endl;

			cout << "Ingrese el tipo de la primera Sala: " << endl; cin>> nombre;
			s->setTipo(nombre);
			cout << "Ingrese el tipo de la segunda Sala: " << endl; cin >> nombre;
			s1->setTipo(nombre);

			cout << endl;



			system("pause");
			system("cls");

			break;

		case 2:
			cout << "--------------------" << endl;
			cout << "  Crear Pelicula " << endl;
			cout << "--------------------" << endl;
			cout << "Ingrese el nombre: " << endl; cin.ignore(); getline(cin, nombre);
			cout << "Ingrese el genero: " << endl;  cin >> genero;
			cout << "Ingrese el tipo (subtitulada o doblada): " << endl; cin >> tipo;
			cout << "Ingrese el tipo de dimension: " << endl; cin >> dimension;
			cout << "Ingrese el tipo de publico (Ninios o Adultos): " << endl; cin >> publico;
			cout << "Ingrese la sipnosis: " << endl; cin.ignore(); getline(cin,sipnosis);
			cout << endl; 

			coleccion->insertarPelicula(new Pelicula(nombre, genero, tipo, dimension, publico, sipnosis));

			system("pause");
			system("cls");

			break;

		case 3:
			if (s->getTipo() != "" && s1->getTipo() != "") {     //Si se creo las 2 salas que entre
				if (coleccion->vectorVacioPeli() == false) {     //Si se creo almenos una pelicula que entre

					cout << "--------------------" << endl;
					cout << "  Crear Funcion " << endl;
					cout << "--------------------" << endl;
					cout << "Ingrese la fecha: " << endl; cin >> fecha;
					cout << "Ingrese la hora: " << endl;  cin >> hora;


					cout << "Cargando..." << endl << endl;

					system("pause");
					system("cls");


					if (coleccion->funcionMaxDia(fecha) != false) {   //Si no hay 2 funciones para ese dia entra
						                                                              
						while (numSala != 2 && numSala != 1) {                           // Si no escoge el numero de opcion correcta se repetira 
							cout << "  *******  SALAS  ********  " << endl << endl;
							cout << " 1. Sala VIP      2. Sala Regular " << endl;
							cout << "Elija el numero de la sala que desea vincular: " << endl; cin >> numSala;

							cout << "Cargando..." << endl << endl;
							system("pause");
							system("cls");
						}
						if (coleccion->disponibilidadSala(numSala, fecha) != false) {   //Si no esta esa sala ocupada para ese dia entra


							cout << "******  PELICULAS  ******" << endl << endl;
							cout << coleccion->ImprimirPelicula();
							cout << "Elija el numero de la pelicula que desea vincular: " << endl; cin >> posicion;

							Pelicula* p = coleccion->buscarPeliPosicion(posicion);

							if (p == NULL) {
								cout << " NO EXISTE LA POSICION " << endl;
							}
							else {
								if (numSala == 1) {

									coleccion->insertarFuncion(new Funcion(fecha, hora, s, p));
									cout << "SE AGREGO EXITOSAMENTE" << endl;

								}
								else {
									coleccion->insertarFuncion(new Funcion(fecha, hora, s1, p));
									cout << "SE AGREGO EXITOSAMENTE" << endl;
								}
							}
						}
						else {
							cout << "SALA OCUPADA YA ESE DIA" << endl << endl;
						}
					}
					else {
						cout << "ERROR, YA EXISTE 2 FUNCIONES PARA ESE DIA" << endl << endl;
					}
				}
				else {
					cout << "NO EXISTE PELICULAS AUN" << endl;
				}
			}
			else {
				cout << "NO SE HAN CREADO LAS 2 SALAS" << endl;
			}

			system("pause");
			system("cls");
			break;

		case 4:

			cout << "***********************************" << endl << endl;
			cout << "        LISTA DE PELICULAS         " << endl;
			cout << "***********************************" << endl << endl;
			cout << coleccion->ImprimirPelicula() << endl << endl;
			cout << "***********************************" << endl << endl;

			system("pause");
			system("cls");
			break;

		case 5:
			cout << "***********************************" << endl << endl;
			cout << "        LISTA DE FUNCIONES         " << endl;
			cout << "***********************************" << endl << endl;
			cout<< coleccion->ImprimirFuncion()<<endl<<endl;
			cout << "***********************************" << endl << endl;

			system("pause");
			system("cls");
			break;

		case 6:
			cout << "--------------------" << endl;
			cout << "  Eliminar pelicula " << endl;
			cout << "--------------------" << endl;
			cout << "(si se elimina la pelicula, se eliminara la funcion que la contenga)" << endl<<endl;

			system("pause");
			system("cls");

			if (coleccion->vectorVacioPeli() == false) {   // si el vector no es vacio que entre

				cout << "Se mostraran las peliculas: " << endl << endl;
				cout << coleccion->ImprimirPelicula() << endl;
				cout << "Elija el numero de la pelicula que desea borrar: " << endl; cin >> posicion;


				if (coleccion->buscarPeliPosicion(posicion) == NULL) {
					cout << " NO EXISTE LA POSICION " << endl;
				}
				else {
					int salida = 0;
					while (salida != 2) {               //Para que se elimine todas las funciones que tenga a esa pelicula

						Funcion* f = coleccion->buscarFuncionxPeli(posicion);

						if (f != NULL) {

							coleccion->eliminarFuncionxPeli(posicion);
						}
						else {
							salida = 2;
						}
					}

					coleccion->eliminarPelicula(posicion);
				}
			}
			else {
				cout << "NO HAY PELICULAS REGISTRADAS" << endl;
			}

			system("pause");
			system("cls");

			break;


		case 7:
			cout << "--------------------" << endl;
			cout << "  Eliminar Funcion " << endl;
			cout << "--------------------" << endl<<endl;
			cout << "(Se elimina por fecha) " << endl << endl;

			system("pause");
			system("cls");

			if (coleccion->vectorVacioFuncion() == false) {  // si el vector no es vacio que entre

				cout << "Elija la fecha para eliminar las funciones: " << endl; cin >> fecha;

				coleccion->eliminarFuncion(fecha);
			}
			else {
				cout << "NO HAY FUNCIONES REGISTRADAS" << endl;
			}

			system("pause");
			system("cls");
			break;

		case 8:
			
			cout << "Saliendo..." << endl << endl;

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

void Cine::menuUsuario(string* s, string* o) {

	int opcion = 0;

	while (opcion != 4) {

		cout << " ------- VENTA DE TIQUETES --------" << endl;
		cout << " 1. Busqueda de peliculas por filtro " << endl;
		cout << " 2. Busqueda de funciones por fecha " << endl;
		cout << " 3. Compra de tiquetes " << endl;
		cout << " 4. Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la funcion a realizar: " << endl;
		cin >> opcion;


		system("pause");
		system("cls");

		string genero = "";  string fecha = ""; int posicion = 0; int numAsientos = 0; int canNinios = 0; int canAdultos = 0;
		int numero = 0; char letra; char respuesta;

		switch (opcion) {

		case 1:

			if (coleccion->vectorVacioFuncion() == false) {     

			cout << "-------------------------" << endl;      //Este metodo es para buscar peliculas si estan registradas en funciones
			cout << " Busqueda de Peliculas " << endl;
			cout << "-------------------------" << endl;
			cout << "Ingrese el genero de pelicula que busca: " << endl; cin >> genero;


			cout << "Cargando..." << endl << endl;
			system("pause");
			system("cls");

			
				Funcion* f = coleccion->buscarFuncionxGenero(genero);    //Se mostrara la pelicula si esta en una funcion, de lo contrario no

				if (f != NULL) {

					cout << coleccion->ImprimirFuncionesxGenero(genero);

				}
				else {
					cout << "NO HAY PELICULAS DE ESTE GENERO REGISTRADAS EN FUNCIONES " << endl;
				}

			}
			else {

				cout << "NO HAY FUNCIONES DISPONIBLES" << endl;
			}

			system("pause");
			system("cls");
			break;

		case 2:

			if (coleccion->vectorVacioFuncion() == false) {
				cout << "-------------------------" << endl;
				cout << "  Busqueda de funciones  " << endl;
				cout << "-------------------------" << endl;
				cout << "Ingrese la fecha que desea ver las funciones: " << endl; cin >> fecha;

				cout << "Cargando..." << endl << endl;
				system("pause");
				system("cls");

				if (coleccion->buscarFuncion(fecha) != NULL) {

					cout<<coleccion->ImprimirFuncionxFecha(fecha);
				}
				else {
					cout << "NO HAY FUNCIONES PARA ESE DIA" << endl;
				}
			}
			else {
				cout << "NO HAY FUNCIONES DISPONIBLES" << endl;
			}

			system("pause");
			system("cls");
			break;


		case 3:
			if (coleccion->vectorVacioFuncion() == false) {
				cout << "-------------------------" << endl;
				cout << "   Compra de tiquetes   " << endl;
				cout << "-------------------------" << endl<<endl;
				cout << "Se mostratara las funciones disponibles: ";
				cout << "(si ya sabe el numero de la funcion a elegir marquelo)" << endl << endl;

				system("pause");
				system("cls");

				cout << coleccion->ImprimirFuncion()<<endl;

				cout << "Numero de la funcion a elegir: " << endl; cin >> posicion;

				system("pause");
				system("cls");

				Funcion* f1 = coleccion->buscarFuncionPosicion(posicion);

				if (f1 != NULL) {

					cout << "Funcion elegida: " << endl << endl;
					cout << f1->toString() << endl << endl;

					string tipoPublico = f1->getPelicula()->getTipoPublico();
					if (tipoPublico == "Ninios" || tipoPublico ==  "ninios") {             //TIPO DE PUBLICO, si es ninios va a entrar

						cout << "Cuantos ninios son: " << endl; cin >> canNinios;
						cout << "Cuantos adultos son: " << endl; cin >> canAdultos;
						numAsientos = canAdultos + canNinios;

						if (f1->getSala()->contadorAsientoDisponibles() >= numAsientos) {        //Si la cantidad de asientos que se quieren es menor a la cantidad de asientos disponibles, entra

							cout << endl << endl;
							cout << "SE MOSTRARA LA SALA..." << endl << endl;
							system("pause");
							system("cls");

							int contador = 0;
							while (numAsientos != contador) {                            //Se repite hasta que acabe de comprar la cantidad de asientos que desea
								cout << f1->getSala()->toString() << endl << endl;

								cout << "Cual asiento desea? (Ponga la letra donde se solicita y despues numero ) " << endl;
								cout << "Letra: "; cin >> letra; cout << "Numero: "; cin >> numero;

								bool estado= f1->getSala()->insertarEstadoAsiento(letra, numero, s);

								if (estado != false) {                                                  // Si el asiento no esta ocupado va a entrar

									system("pause");
									system("cls");

									cout << f1->getSala()->toString() << endl << endl;

									cout << "Desea confirmar el asiento? S/N " << endl; cin >> respuesta;


									f1->getSala()->confirmacionEstadoAsiento(respuesta, s, o);       //Si no confirma el asiento, vuelve a disponible el asiento seleccionado 
									if (respuesta == 'n' || respuesta == 'N') {                       //y vuelve a dar la opcion de elegir otro asiento

										system("pause");
										system("cls");

										cout << "Reeleccion..." << endl;

									}
									else {

										system("pause");
										system("cls");

										cout << f1->getSala()->toString() << endl << endl;

										cout << "Desea confirmar la compra de este asiento? S/N " << endl; cin >> respuesta;          

										bool op = f1->getSala()->confirmacionCompra(letra, numero, respuesta);

										if (op == true) {                                                    //Si responde que si compra el asiento va a imprimir el
											                                                                 // tiquete, de lo contario vuelve a dar la opcion de elegir otro asiento.
											system("pause");                                                 
											system("cls");
											cout << "Imprimiendo tiquete " << letra << numero << "..." << endl;
											system("pause");
											system("cls");

											cout << "ASIENTO ELEGIDO " << letra << numero << endl;
											cout << f1->toString() << endl;

											contador++;

											if (numAsientos > contador) {

												cout << "ELEGIR SIGUIENTE ASIENTO..." << endl;
												system("pause");
												system("cls");
											}
										}
										else {
											system("pause");
											system("cls");

											cout << "Reeleccion..." << endl << endl;

										}
									}
								}
								else {
									system("pause");
									system("cls");

									cout << "ASIENTO OCUPADO.." << endl;
									cout << "Por favor elija otro asiento" << endl;

									system("pause");
									system("cls");

									}
								

							}                                                            //Final de la compra, sale el precio total de los asientos
							
							system("pause");
							system("cls");

							cout << "COMPRA EXITOSA" << endl << endl;
							cout << "TOTAL DE LA COMPRA: " << calcularPrecioTiquete(canNinios, canAdultos, f1->getSala()->getTipo()) << endl;

							system("pause");
							system("cls");
							
							contador = 0;

						}
						else {
							cout << "NO HAY ESPACIO PARA " << numAsientos << endl;
						}
					}
					else {                                                                     //TIPO DE PUBLICO, si es adultos va a entrar
						cout << "** NO SE PERMITEN NINIO " << endl;
						cout << "Cuantos adultos son: " << endl; cin >> canAdultos;

						numAsientos = canAdultos;

						if (f1->getSala()->contadorAsientoDisponibles() >= numAsientos) {

							cout << endl << endl;
							cout << "SE MOSTRARA LA SALA..." << endl << endl;
							system("pause");
							system("cls");

							int contador = 0;
							while (numAsientos != contador) {                               //Se repite hasta que acabe de comprar la cantidad de asientos que desea
								cout << f1->getSala()->toString() << endl << endl;

								cout << "Cual asiento desea? (Ponga la letra donde se solicita y despues numero ) " << endl;
								cout << "Letra: "; cin >> letra; cout << "Numero: "; cin >> numero;
								
								bool estado = f1->getSala()->insertarEstadoAsiento(letra, numero, s);
								if (estado != false) {                                                          //Si responde que si desea ocupar el asiento va a entrar
											                                                               
									system("pause");
									system("cls");

									cout << f1->getSala()->toString() << endl << endl;

									cout << "Desea confirmar el asiento? S/N " << endl; cin >> respuesta;

									f1->getSala()->confirmacionEstadoAsiento(respuesta, s, o);     //Si no confirma el asiento, vuelve a disponible el asiento seleccionado
									if (respuesta == 'n' || respuesta == 'N') {                   // y vuelve a dar la opcion de elegir otro asiento

										system("pause");
										system("cls");

										cout << "Reeleccion..." << endl;

									}
									else {

										system("pause");
										system("cls");

										cout << f1->getSala()->toString() << endl << endl;

										cout << "Desea confirmar la compra de este asiento? S/N " << endl; cin >> respuesta;

										bool op = f1->getSala()->confirmacionCompra(letra, numero, respuesta);

										if (op == true) {                                                     //Si responde que si compra el asiento va a imprimir el
																											 // tiquete, de lo contario vuelve a dar la opcion de elegir otro asiento.
											system("pause");
											system("cls");
											cout << "Imprimiendo tiquete " << letra << numero << "..." << endl;
											system("pause");
											system("cls");

											cout << "ASIENTO ELEGIDO " << letra << numero << endl;
											cout << f1->toString() << endl;

											contador++;

											if (numAsientos > contador) {

												cout << "ELEGIR SIGUIENTE ASIENTO..." << endl;
												system("pause");
												system("cls");
											}
										}
										else {

											system("pause");
											system("cls");

											cout << "Reeleccion..." << endl << endl;
										}
									}
								}
								else {
									system("pause");
									system("cls");

									cout << "ASIENTO OCUPADO.." << endl;
									cout << "Por favor elija otro asiento" << endl;

									system("pause");
									system("cls");

								}
							}                                                        //Final de la compra, sale el precio total de los asientos
							cout << "COMPRA EXITOSA" << endl << endl;
							cout << "TOTAL DE LA COMPRA: " << calcularPrecioTiquete(0, canAdultos, f1->getSala()->getTipo()) << endl;

							system("pause");
							system("cls");

							contador = 0;
						}
						else {
							cout << "NO HAY ESPACIO PARA " << numAsientos << endl;
						}
					}
				}
				else {
					cout << "ESA POSICION NO EXISTE" << endl;
				}
			}
			else {
				cout << "NO HAY FUNCIONES DISPONIBLES" << endl;
			}

			system("pause");
			system("cls");
			break;

		}

	}

}


void Cine::menu() {


	string* se = new string("Seleccionado");
	string* o = new string("Ocupado");

	int opcion = 0;

	while (opcion != 3) {

		cout << " ------------ MENU ---------------" << endl;
		cout << " 1. Administrar Funciones (Administrador)" << endl;
		cout << " 2. Compra de tiquetes (Cliente)" << endl;
		cout << " 3.Salir " << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: " << endl;
		cin >> opcion;


		system("pause");
		system("cls");


		switch (opcion) {

		case 1:

			menuAdministrador();

			system("pause");
			system("cls");

			break;

		case 2:

			menuUsuario(se, o);
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

	delete se, o;
}