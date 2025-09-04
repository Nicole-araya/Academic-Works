#include"Cajero.h"
#include"Supervisor.h"
#include"Interfaz.h"
#include"Departamento.h"
#include"Tienda.h"
#include"Empleado.h"
using namespace std;

int main() {
	Tienda* t = NULL;
	Departamento* d = NULL;
	Fecha* f = NULL;
	Empleado* e = NULL;
	int op, num, cod, can, id, di, m, a, hr;
	double sxH = 9000; double cuota = 800000;
	double totalV; double porceComis = 0.15; double porceRecar= 0.10;

	string nom, cat, desc, fech;
	do {
		op = Interfaz::menu();
		system("pause");
		system("cls");

		switch (op) {
		  case 1:{
			   cout << ">>>>  1 - Crear e ingresar Departamento con su respectivo codigo." << endl<<endl;

			   cout << "Ingrese la cantidad de departamentos: "; cin >> num;
			   t = new Tienda(num);

			   system("pause");
			   system("cls");

			   for (int i = 0;i < num;i++) {


				   cout << "Ingrese el codigo del departamento #" <<i <<": "; cin >> cod;
				   cout << "Ingrese la descripcion del departamento #" << i << ": "; cin.ignore(); getline(cin, desc);
				   cout << "Ingrese la cantidad de empleados en el departamento #" << i << ": "; cin >> can;


				   d = new Departamento(can);
				   d->setCodigo(cod);
				   d->setDescripcion(desc);

				   if (t->ingresaDepartamento(d) != true) {

					   cout << "Ingrese repetido..." << endl;
					   system("pause");
					   system("cls");

					   cout << "Ingrese el codigo del departamento #" << i << ": "; cin >> cod;
					   cout << "Ingrese la cantidad de empleados en el departamento #" << i << ": "; cin >> can;

					   d = new Departamento(can);
					   d->setCodigo(cod);
				   }

				   system("pause");
				   system("cls");

			   }

			   cout << t->toString();

			   system("pause");
			   system("cls");

			   break;
		  }

		  case 2: {
			   cout << ">>>>  2 - Ingresar un empleado cajero en un determinado departamento." << endl;

				   cout << "Fecha de ingreso" << endl;
				   cout << "Dia: "; cin >> di;
				   cout << "Mes: "; cin >> m;
				   cout << "Annio: "; cin >> a;

				   cout << "Ingrese el nombre del empleado: "; cin.ignore(); getline(cin, nom);
				   cout << "Ingrese el id del empleado: ";  cin >> id;
				   cout << "Ingrese el cod del departamento: ";  cin >> cod;
				   cout << "Ingrese las horas de trabajo: "; cin >> hr;


				   if (t->buscar(cod) != NULL && d->buscar(id) == NULL) {
					   d = t->buscar(cod);
					   f = new Fecha(di, m, a);

					   d->ingresaEmpleado(new Cajero(id, nom, "002", f,hr,sxH));

					   cout << "Insertando empleado... " << endl << endl;
					   system("pause");
					   system("cls");
					   cout << d->toString();
				   }
				   else cout << "No se pude realizar la opcion" << endl;

			   system("pause");
			   system("cls");
 

			   break;
		  }
		  case 3: {
			   cout << ">>>>  3 - Ingresar un empleado vendedor en un determinado departamento." << endl;

				   cout << "Fecha de ingreso" << endl;
				   cout << "Dia: "; cin >> di;
				   cout << "Mes: "; cin >> m;
				   cout << "Annio: "; cin >> a;

				   cout << "Ingrese el nombre del empleado: "; cin.ignore(); getline(cin, nom);
				   cout << "Ingrese el id del empleado: ";  cin >> id;
				   cout << "Ingrese el cod del departamento: ";  cin >> cod;

				   d = t->buscar(cod);
				   if (d != NULL && d->buscar(id) == NULL) {

					   cout << "Ingrese el total de ventas: ";  cin >> totalV;

					   f = new Fecha(di, m, a);

					   d->ingresaEmpleado(new Vendedor(id, nom, "002", f, cuota, totalV, porceComis));

					   cout << "Insertando empleado... " << endl << endl;
					   system("pause");
					   system("cls");
					   cout << d->toString();
				   }
				   else cout << "No se pude realizar la opcion" << endl;


			   system("pause");
			   system("cls");
			   break;
		  }
		  case 4: {
			   cout << ">>>>  4 - Ingresar un empleado supervisor en un determinado departamento." << endl;

				   cout << "Fecha de ingreso" << endl;
				   cout << "Dia: "; cin >> di;
				   cout << "Mes: "; cin >> m;
				   cout << "Annio: "; cin >> a;

				   cout << "Ingrese el cod del departamento: ";  cin >> cod;
				   d = t->buscar(cod);

				   if (d != NULL) {

					   cout << "Ingrese el id del empleado: ";  cin >> id;

					   e = d->buscar(id);

					   if (e != NULL) {

						   nom = e->getNombre();
						   f = e->getFecha();
						   cat = e->getCategoria();

						   d->EliminarPuesto(e);

						   cout << "Ingrese el total de ventas: ";  cin >> totalV;

						   d->ingresaEmpleado(new Supervisor(id, nom, cat, f, cuota, totalV, porceComis, porceRecar));

					   }
					   else {

						   cout << "Ingrese el nombre del empleado: "; cin.ignore(); getline(cin, nom);



						   f = new Fecha(di, m, a);

						   d->ingresaEmpleado(new Vendedor(id, nom, "002", f));

						   cout << "Insertando empleado... " << endl << endl;
						   cout << d->toString();
					   }
				   }
				   else cout << "No existe departamento" << endl;

				   system("pause");
				   system("cls");
			   break;

		  }
		  case 5: {
			   cout << ">>>>  5 - Opcion para recalificar a cualquier empleado por su ID. " << endl;

			   cout << "Ingrese el id del empleado: ";  cin >> id;
			   e = t->buscarEmpleado(id);
			   
			   if (e != NULL) {
				   cout << "Ingrese la categoria que desea dar: ";  cin >> cat;

				   e->setCategoria(cat);
			   }
			   else {
				   cout << "No existe empleado";
			   }



			   system("pause");
			   system("cls");
			   break;
		  }
		  case 6: {
			   cout << ">>>>  6 - Reportar cada empleado que tiene la tienda y la cantidad total de ellos." << endl;

			   cout<< t->imprimirEmpleadosT();


			   system("pause");
			   system("cls");

		  }break;
		  case 7: {
			   cout << ">>>>  7 - Reportar ID, nombre y salario de todos los cajeros de la tienda." << endl;



			   system("pause");
			   system("cls");

			   break;
		  }
		  case 8: {
			   cout << ">>>>  8 - Reportar cada empleado y el salario total de los empleados de un determinado departamento." << endl;

			   cout << "Ingrese el cod del departamento: ";  cin >> cod;
			   d = t->buscar(cod);

			   if (d != NULL) {

				   cout<< d->reportarEmpleados();

			   }


			   system("pause");
			   system("cls");
			   break;
		  }

		  case 9: {
			   cout << ">>>>  9 - Reportar los empleados que ingresaron el mismo dia a la tienda." << endl;
			   cout << "Ingrese la fecha" << endl;
			   cout << "Dia: "; cin >> di;
			   cout << "Mes: "; cin >> m;
			   cout << "Annio: "; cin >> a;


			   cout << t->imprimirMismoDia(new Fecha(di, m, a));


			   system("pause");
			   system("cls");
			   break;
		  }
		  case 10: {
			   cout << ">>>> 10 - Reportar los empleados que ingresaron el mismo dia en un determinado departamento." << endl;
			   cout << "Ingrese el cod del departamento: ";  cin >> cod;
			   d = t->buscar(cod);

			   if (d != NULL) {

				   cout << "Ingrese la fecha" << endl;
				   cout << "Dia: "; cin >> di;
				   cout << "Mes: "; cin >> m;
				   cout << "Annio: "; cin >> a;

				   f = new Fecha(di, m, a);

				   cout << d->reportarMismoDia(f);


			   }

			   system("pause");
			   system("cls");

			   break;
		  }
		  case 11: {
			   cout << ">>>> 11 - Reportar los empleados y la suma del salario total de toda la tienda. " << endl;

			   cout << t->imprimirSalario();


			   system("pause");
			   system("cls");

			   break;
		  }
		  case 12: {
			   cout << ">>>> 12 - Reportar los empleados, que son cajeros de una determinada categoria. " << endl;

			   Empleado* pa = new Supervisor();
			   Cajero* p = dynamic_cast<Cajero*>(pa);



			   system("pause");
			   system("cls");

			   break;
		  }
		  case 13: {
			   cout << ">>>> 13 - Reportar los empleados de la tienda que son supervisores y que ingresaron juntos en una fecha determinada." << endl;


			   system("pause");
			   system("cls");

			   break;
		  }
		  case 14: {
			   cout << ">>>> 14 - Reportar el empleado que tiene el mayor salario de toda la tienda." << endl;

			  // cout << t->imprimirMayorSalario();



			   system("pause");
			   system("cls");

			   break;

		  }
		  case 15: {
			   cout << ">>>> 15 - Salir." << endl;

		  }break;
		  default: cout << ">>>> ERROR: Digite una opcion valida." << endl;
		};
		
		
		// fin del switch

		system("pause");

	} while (op != 15);  // fin del while

	return 0;
}
