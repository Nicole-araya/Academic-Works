#include"ContenedorL.h"

int main() {


	cout << "------------TRABAJANDO CON CONTENEDORES TIPO LISTA------------------" << endl;
	cout << endl;


	cout << " Creacion de CONTENEDOR-1 TIPO LISTA Y PRODUCTOS...." << endl;

	ContenedorL* l1 = new ContenedorL();

	cout << endl << endl;


	cout << "Ingresando productos a ContenedorL-1" << endl;


	l1->ingresarProducto(new Producto("HARINA", 1000));
	l1->ingresarProducto(new Producto("ARROZ", 2000));
	l1->ingresarProducto(new Producto("SAL", 500));
	l1->ingresarProducto(new Producto("HARINA", 1000));

	cout << endl << endl;


	cout << " Creacion de CONTENEDOR-2 TIPO LISTA Y PRODUCTOS...." << endl;

	ContenedorL* l2 = new ContenedorL();
	
	
	cout << "Ingresando productos a ContenedorL-2" << endl;
	
	l2->ingresarProducto(new Producto("HARINA", 1000));
	l2->ingresarProducto(new Producto("ARROZ", 2000));
	l2->ingresarProducto(new Producto("SAL", 500));

	cout << endl << endl;


	cout << "---------------IMPRIMIENDO CONTENEDORES------------------" << endl;
	
	cout << "  CONTENEDOR-1 " << endl;
	cout<< l1->toString();
	cout << endl << endl;


	cout << "  CONTENEDOR-2 " << endl;
	cout << l2->toString();
	cout << endl << endl;
	cout << endl << endl;


	cout << "----------------COMPARACION DE CONTENEDORES----------------" << endl;
	cout << endl;

	/*if (l1->compararaListasIguales(l2))
		cout << "Si son iguales." << endl;
	else
		cout << "No son iguales." << endl;
		*/
	system("pause");
	return 0;
}

