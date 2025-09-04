#include"Interfaz.h"

int Interfaz::menu() {
	int op = 0;
	

	    cout << "-------------------------------------------------- MENU-------------------------------------------------------" << endl;
	    cout << " 1 - Crear e ingresar Departamento con su respectivo codigo." << endl;
		cout << " 2 - Ingresar un empleado cajero en un determinado departamento." << endl;
		cout << " 3 - Ingresar un empleado vendedor en un determinado departamento." << endl;
		cout << " 4 - Ingresar un empleado supervisor en un determinado departamento." << endl;
		cout << " 5 - Opcion para recalificar el empleado por su ID. " << endl;
		cout << " 6 - Reportar cada empleado que tiene la tienda y la cantidad total de ellos." << endl;
		cout << " 7 - Reportar ID, nombre y salario de todos los cajeros de la tienda." << endl;
		cout << " 8 - Reportar cada empleado y el salario total de los empleados de un determinado departamento." << endl;
		cout << " 9 - Reportar los empleados que ingresaron el mismo dia a la tienda." << endl;
		cout << "10 - Reportar los empleados que ingresaron el mismo dia en un determinado departo." << endl;
		cout << "11 - Reportar los empleados y la suma del salario total de todos ellos. " << endl;
		cout << "12 - Reportar los empleados, que son cajeros de una determinada categoria. " << endl;
		cout << "13 - Reportar los empleados de la tienda que son supervisores y que ingresaron juntos en una fecha determinada." << endl;
		cout << "14 - Reportar el empleado que tiene el mayor salario de toda la tienda." << endl;
		cout << "15 - Salir." << endl;
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		cout << "  Digitar la opcion: ";
		cin >> op;
		
		return op;
}

/*Empleado* Interfaz::creaEmpleado()
{
	int op, id;
	string nom, cat;
	Fecha* f = NULL;

	Empleado* emp = NULL;
	cout << "--CREACION DE UN EMPLEADO--" << endl;
	cout << "-- 1 --> Empleado"   << endl;
	cout << "-- 2 --> Cajero"     << endl;
	cout << "-- 3 --> Vendedor"   << endl;
	cout << "-- 4 --> Supervisor" << endl;
	cout << "Digite la opcion: ";
	cin >> op;

	system("pause");
	system("cls");

	if (op == 1) {
		cout << "\n Digite id: ";cin >> id;
		cout << "Digite el nombre: "; cin.ignore(); getline(cin, nom);
		cout << "\n Digite la categoria: ";cin >> cat;
		f = creaFecha();

		emp = new Empleado(id, nom, cat, f);
	}
	//if(op)


}*/

/*Fecha* Interfaz::creaFecha() {
	int d, m, a;
	cout << "--CREACION DE FECHA--" << endl;
	cout << "Digite el dia: ";
	cin >> d;
	cout << "Digite el mes: ";
	cin >> m;
	cout << "Digite el anio: ";
	cin >> a;
	return new Fecha(d, m, a);
}*/