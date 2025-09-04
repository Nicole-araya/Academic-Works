#include "TiendaRopa.h"

TiendaRopa::TiendaRopa(){
	ventas = new ContenedoraVentas();
	trajes = new ContenedoraTrajes();
	catalogo = new CatalogoEnLinea(trajes);
	trajePersonalizado = new ContenedoraTrajesPersonalizados();
	contador =0;  
}
TiendaRopa::~TiendaRopa()
{
	delete catalogo, trajes, ventas, trajePersonalizado;
}


void TiendaRopa::menuAdministrador(){

	int opcion=0;   TrajeAbstracto* varTraje;
	string medida, color;  Venta* venta;
	CatalogoEnLinea* cat = (CatalogoEnLinea*)(catalogo);
	string codigo;


	while (opcion != 8) {
		cls;
		cout << "   Menu Administrador   " << endl;
		cout << "========================" << endl;
		cout << "1. Agregar traje" << endl;
		cout << "2. Eliminar traje" << endl;
		cout << "3. Trajes en stock" << endl;
		cout << "4. Ver clientes fisicos" << endl;
		cout << "5. Ver clientes Empresa" << endl;
		cout << "6. Ver historial de Ventas" << endl;
		cout << "7. Datos de Ventas" << endl;
		cout << "8. >Volver<" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		cls;

		switch (opcion) {
		case 1: 
			
			varTraje = crearTraje(true);

			trajes->ingresaTraje(varTraje);

            // Se nofica la entrada de un traje a los subscritores
			cout << endl;
			cat->notificar(true);

			break;
		
		case 2:

			cout << "--Eliminar traje--" << endl;
			cout << trajes->toString();
			cout << "Codigo del traje a eliminar: ";
			cin >> codigo;

			varTraje= trajes->buscaPorCod(codigo);
			if (varTraje) {

				trajes->eliminaTraje(varTraje);
				cout << "Traje eliminado..." << endl;


				cat->notificar(false);          // Se nofica la eliminacion de un traje a los subscritores
			}
			else {
				throw varTraje;  // no se encuentra el traje, excepcion
			}

			break;

		case 3:
			cout << trajes->toString();
			break;

		case 4:
			
			cout << "--Clientes Fisicos--" << endl;
			cout << catalogo->tipoCliente(true);
			break;

		case 5:
			cout << "--Clientes empresa--" << endl;
			cout << catalogo->tipoCliente(false);
			break;
		case 6:
			cout << "--Historial Ventas--" << endl<<endl;
			cout << ventas->toString() << endl;

			break;
		case 7:

			cout << "---Datos de Ventas---" << endl;
			cout << "Ventas Total sin Ganancias: " << ventas->ventasTotalSinGanancia() << endl;
			cout << "Ventas Total con Ganancias: " << ventas->ventasTotalConGanancia() << endl;
			cout << "Ventas Total Netas: " << ventas->ventasTotalNetas() << endl<<endl;
			cout << ">>>Traje mas vendido<<<\n";
			venta = ventas->trajeMasVendido(); 
			if (venta) { cout<< venta->getTraje()->toString() << endl; }

			break;

		case 8:
			cout << "Volviendo al menu Principal" << endl;
			break;

		default:

			cin.clear();
			throw opcion;

		}
		pause;
	}
}


void TiendaRopa::menuTiendaLinea() {

	Observa *clienteCompra; Cliente* cliente;
	TrajeAbstracto* trajeCompra = NULL;

	Venta* venta;
	int opc,opcion=0, opcCliente;

	string id,nombre,corr,pais,ciudad, compra,fecha;
	double pago=0;
	
	while (opcion != 3) {
		cls;
		cout << "   Tienda en linea  " << endl;
		cout << "=====================" << endl;
		cout << "1. Ingresar al Catalogo" << endl;
		cout << "2. Ingresar nuevo suscriptor" << endl;
		cout << "3. Volver" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		cls;

		switch (opcion) {
		case 1:

			cout << "ID del cliente: ";
			cin >> id;

			clienteCompra = catalogo->buscaPorID(id);  //si no existe, tira exepcion
			if (clienteCompra == NULL) {
				throw clienteCompra;
			}

			cliente = (Cliente*)(clienteCompra);

			cout << "===Tienda en linea===" << endl;
			cout << "1. Traje del stock" << endl;
			cout << "2. Traje personalizado" << endl;
			cout << "Opcion: ";
			cin >> opc;
			cls;

			if(opc == 1){
				cout << "   Trajes disponibles  " << endl;
				cout << "-----------------------" << endl;
				cout << trajes->toString();

				cout << "\nCodigo del traje que desea comprar: ";
				cin >> compra;
				trajeCompra = trajes->buscaPorCod(compra);

				if(trajeCompra == NULL) {   //Si no existe tira exepcion
					throw trajeCompra;
				}

			} else if(opc == 2){
				trajeCompra = crearTraje(false);

				trajePersonalizado->ingresaTraje(trajeCompra);
			}
			else {
				throw opc;  //error de opcion
			}

			pause;
			cls;
			cout << "Ingrese la fecha de hoy: ";  cin.ignore(); getline(cin, fecha);
			cout << endl << trajeCompra->toString() << endl;
			cout << "Comprando traje..." << endl;

			
			venta = new Venta(cliente, trajeCompra, fecha); 
			venta->calcularPrecioE();
			cout << "Calculando precio de envio...\n" << endl;
			ventas->agregaVenta(venta);

			pause;
			cls;
			cout << venta->factura() << endl;
			pause;
			cls;

			break;
		case 2:

			cls;
			cout << ">>Nueva suscripcion<<  " << endl;
			cout << "-----------------------" << endl;
			cout << "1. Cliente unico" << endl;
			cout << "2. Empresa" << endl;
			cout << "Elija el tipo de subscriptor: ";
			cin >> opcCliente;
			cls;

			opcCliente == 2 ? cout << "Subcriptor Empresa" << endl : cout << "Subcriptor Cliente unico" << endl;

			if (opcCliente == 1) {
				cout << "Cedula cliente: ";
				cin >> id;

			}else if (opcCliente == 2) {
				cout << "Cedula juridica: ";
				cin >> id;

			}else {
				throw opcCliente;
			}

			clienteCompra = catalogo->buscaPorID(id);  //si existe el cliente, tira exepcion
			if (clienteCompra != NULL) {
				throw clienteCompra;
			}

			cout << "Nombre: ";
			cin.ignore();
			getline(cin, nombre);

			cout << "Correo: ";
			cin >> corr;

			cout << "===Paises de envio disponibles===" << endl;
			cout << "1. EEUU, New York " << endl;
			cout << "2. Francia, Paris" << endl;
			cout << "3. Italia, Milan" << endl;
			cout << "4. Brasil, Brasilia" << endl;
			cout << "5. Argentina, Buenos Aires" << endl;
			cout << "6. Canada, Ontario" << endl;
			cout << "7. Inglaterra, Londres" << endl;
			cout << "8. EEUU, California" << endl;
			cout << "9. Costa Rica" << endl;
			cout << "Ingrese el pais para el envio: ";
			cin >> opc;

			switch(opc){
			case 1:
				pais = "EEUU";
				ciudad = "New York";
				break;
			case 2:
				pais = "Francia";
				ciudad = "Paris";
				break;
			case 3:
				pais = "Italia";
				ciudad = "Milan";
				break;
			case 4:
				pais = "Brasil";
				ciudad = "Brasilia";
				break;
			case 5:
				pais = "Argentina";
				ciudad = "Buenos Aires";
				break;
			case 6:
				pais = "Canada";
				ciudad = "Ontario";
				break;
			case 7:
				pais = "Inglaterra";
				ciudad = "Londres";
				break;
			case 8:
				pais = "EEUU";
				ciudad = "California";
				break;
			case 9:	
				pais = "CR";
				ciudad = "Local";
				break;
			default:
				throw opc; // error opcion
				break;
			}

			opcCliente == 1 ? clienteCompra = new Persona(id, nombre, corr, 200, ciudad, pais, pais) :
				clienteCompra = new Empresa(id, nombre, corr, 400, ciudad, pais, false);

			catalogo->agregarSubscriptor(clienteCompra);
			cout << "Nuevo suscriptor agregado" << endl;


			break;
		case 3:
			cout << ">>Volviendo<<" << endl;
			break;

		default:
			cin.clear();
			throw opcion;
			break;
		}

		pause;
		cls;

	}
}

void TiendaRopa::menuTiendaFisica()
{
	int opcion=0; string compra, fecha;  TrajeAbstracto* trajeCompra; Venta* venta;

	
	while (opcion != 2) {
		cls;
		cout << "   Tienda Fisica     " << endl;
		cout << "=====================" << endl;
		cout << "1. Comprar traje" << endl;
		cout << "2. Volver" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		pause;
		cls;

		switch (opcion) {
		case 1:

			cout << trajes->toString();

			cout << "\nCodigo del traje que desea comprar: ";
			cin >> compra;

			trajeCompra = trajes->buscaPorCod(compra);

			if (trajeCompra == NULL) {   //Si no existe tira excepcion
				throw trajeCompra;
			}
			pause;
			cls;

			cout << "Ingrese la fecha de hoy: "; cin.ignore(); getline(cin, fecha);
			cout << endl << trajeCompra->toString() << endl;
			cout << "Comprando traje..." << endl;

			venta = new Venta(NULL, trajeCompra, fecha); 

			cout << "Calculando preciode envio..." << endl;
			ventas->agregaVenta(venta);

			pause;
			cls;
			cout << venta->factura() << endl;
			pause;
			cls;
			break;
		case 2:

			cout << ">>Volviendo al menu Principal<<" << endl;
			pause;
			cls;
			break;
		default:

			cin.clear();
			throw opcion;
		}
	}


}

TrajeAbstracto* TiendaRopa:: crearTraje(bool cod){
	TrajeAbstracto* varTraje = NULL;
	string codigo, medida, color, varcod;
	int opc = 0;;
	CamisaAbstracta* camisa; PantalonAbstracto* panta; ZapatoAbstracto* zapato; 
	bool var;

	cout << "      Crear Traje   " << endl;
	cout << "-----------------------" << endl;

	cout << "1. Traje deportivo" << endl;
	cout << "2. Traje ejecutivo" << endl;
	cout << "3. Traje de trabajo" << endl;
	cout << "-----------------------" << endl;
	cout << "Elija un tipo de traje: ";
	cin >> opc;

	if (opc == 1) {
		varcod = "D" + varcod;

	}
	else if (opc == 2) {
		varcod = "E" + varcod;

	}
	else if (opc == 3) {
		varcod = "T" + varcod;
	}
	else {

		throw opc;    //error de OPCION
	}

	if(cod) {    // Si es true es porque es de creado en Menu Admi

		cout << "\nIngresar el codigo del traje: "; cin >> codigo;
		codigo = varcod + codigo;

		varTraje = trajes->buscaPorCod(codigo);
			if(varTraje != NULL) {
				throw varTraje;          // EXEPCION DE QUE SE ENCUENTRA YA
			}


	}else {     //De lo contrario, lo esta creando un cliente, traje personalizado
		
		codigo = varcod+ "P" + to_string(contador); 
		contador++;
	}

	cout << endl << "        Medidas     " << endl;
	cout << "-----------------------" << endl;
	cout << "l) Grande" << endl;
	cout << "m) Mediano" << endl;
	cout << "s) Pequenio" << endl;
	cout << "n) Ninio" << endl;
	cout << "-----------------------" << endl;
	cout << endl << "Ingrese la medida del traje (l,m,s,n): "; cin >> medida;


	if(medida != "l" && medida != "m" && medida != "s" && medida != "n") {
		throw opc;                            // EXEPCION DE OPCION entero, ya que va caer en el mismo mensaje de error que los enteros
	}


	if(opc == 1) {
		varTraje = new TrajeDeportivo(codigo, medida);

	} else if(opc == 2) {
		varTraje = new TrajeEjecutivo(codigo, medida);

	} else if(opc == 3) {
		varTraje = new TrajeTrabajo(codigo, medida);
	} else {

		throw opc;    //error de OPCION
	}

	cls;

	cout << "Crear partes del Traje" << endl;
	cout << "-----------------------" << endl;

	//Camisa
	cout << "\nColor de la camisa: ";
	cin.ignore();
	getline(cin, color);

	camisa = varTraje->crearCamisa(color);

	cout << camisa->getdescripcion() << "Ingrese su preferencia: ";     //Descripcion de como va a ser 
	cin >> var;
	camisa->setBoolOpc(var);
	varTraje->setOpcCamisa(var);

	//Pantalon
	cout << "\nColor del pantalon: ";
	cin.ignore();
	getline(cin, color);

	panta = varTraje->crearPantalon(color);
	cout << panta->getdescripcion() << "Ingrese su preferencia: ";  //Descripcion de como va a ser
	cin >> var;
	panta->setBoolOpc(var);
	varTraje->setOpcPant(var);


	//Zapatos
	cout << "\nColor de los zapatos: ";
	cin.ignore();
	getline(cin, color);

	zapato = varTraje->crearZapatos(color);
	cout << zapato->getdescripcion() << "Ingrese su preferencia: ";    //Descripcion de como va a ser
	cin >> var;
	zapato->setOpc(var);
	varTraje->setOpcZapatos(var);


	varTraje->setPreciosRopa();
	varTraje->calculaPrecio();   //PRECIO DEL TRAJE BASE

	return varTraje; 
}


void TiendaRopa::menuPrincipal(){
	int opcion = 0; bool entra = 1;
	string archivoVenta = "Ventas.txt", archivoTraje = "Trajes.txt", archivoSubscriptores = "Subscriptores.txt";

	
	while (opcion!=4) {

		try {
			if (entra) {      //Si es la primera vez entrando 
                                                   // Abre los archivos y lo cierra, si no existiera los archivos los crea.
				CargaArchivos::crearArchivos(archivoTraje, archivoSubscriptores, archivoVenta);  
																		//Carga los datos si hay, y los inserta en las listas
				CargaArchivos::cargarTrajes(archivoTraje, trajes, trajePersonalizado);
				CargaArchivos::cargarSubcriptores(archivoSubscriptores, catalogo);
				CargaArchivos::cargarVentas(archivoVenta, ventas, catalogo, trajes, trajePersonalizado);
				cout << "Cargando los Datos..." << endl << endl;
				contador = trajePersonalizado->contador();

				entra = 0;
				pause;
			}

			cls;
			cout << " =====================" << endl;
			cout << "||       TIENDA      ||" << endl;
			cout << " =====================" << endl;
			cout << "1. Menu Administrador" << endl;
			cout << "2. Ventas en Fisico" << endl;
			cout << "3. Ventas en Linea" << endl;
			cout << "4. Salir..." << endl;
			cout << "Opcion: ";
			cin >> opcion;

			switch (opcion) {

			case 1:

				menuAdministrador();

				break;
			case 2:

				menuTiendaFisica();

				break;
			case 3:

				menuTiendaLinea();

				break;
			case 4:
				cls;
				cout << "Saliendo del programa..." << endl;

				ventas->guardarDatos(archivoVenta);
				trajes->guardarDatos(archivoTraje);
				trajePersonalizado->guardarDatos(archivoTraje);
				catalogo->guardarSubscriptores(archivoSubscriptores);
				pause;
				
				break;
			default:
				cin.clear();
				throw opcion;
				break;
			}

		}
		catch (int num) {

			if (!num) {
				cin.ignore();
				cout << LetterOption::excepcion();
			}
			else {
				cout << NotFound::excepcion();
			}
			system("pause");
			system("cls");
		}
		catch (Observa* ob) {

			if (ob) {
				cout << Found::excepcion();
			}
			else {
				cout << NotFound::excepcion();
			}
			system("pause");
			system("cls");
		}
		catch (TrajeAbstracto* tr) {

			if (tr) {
				cout << Found::excepcion();
			}
			else {
				cout << NotFound::excepcion();
			}
			system("pause");
			system("cls");
		}
		
		catch (fstream& f) {

			cout << Downloading::excepcion();
			f.close();                        
			system("pause");
			system("cls");
		}

	}


}