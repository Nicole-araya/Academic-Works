#include"AViaje.h"

int main() {

	int cat = 0;


	cout << "-------------VIAJES DE COSTA RICA-----------------" << endl;
	cout << "Creacion de un objeto AViaje...." << endl<<endl;
	cout << endl;
	system("pause");
	cout << endl;

	AViaje* v = new AViaje("VIAJES COSTA RICA", "1234", "2222 7777");

	cout << v->toString()<<endl;

	cout << endl;

	cout << "Ingrese el codigo o categoria del viaje: ";
	cin >> cat;

	cout << endl;
	system("pause");
	cout << endl;

	cout << "Con base en lo anterior, se tiene que: " << endl;
	cout << endl;

	v->infoDelViaje( cat);

	cout << endl;
	system("pause");


	delete v;

	return 0;
}