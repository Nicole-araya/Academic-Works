#include "ArchivoLeer.h"

ArchivoLeer::ArchivoLeer()
{
	//ctor
}

ArchivoLeer::~ArchivoLeer()
{
	//dtor
}

void ArchivoLeer::leerArchivo(string nom) {

		char linea[128];
	ifstream entrada(nom);

		if (!entrada) {

			throw entrada;

			entrada.close();
			return;
		}

		while (!entrada.eof()) {

			entrada.getline(linea, sizeof(linea));

			cout << linea << endl;

		}
	
	entrada.close();


}
