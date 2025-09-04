#include "Archivo.h"

void Archivo::cargarDatosTransporte(ListaTransporte* lt, string nom)
{
	string cod, nomb, num, por;  
	RestriccionTransporte* t;

	ifstream entrada(nom);

	if (!entrada) {

		throw entrada; 
		entrada.close();
		return;
	}

	while (!entrada.eof()) {

		getline(entrada, nomb, '\t');
		getline(entrada, cod, '\t');
		getline(entrada, num, '\t');
		getline(entrada, por, '\n');

		if (!cod.empty() && !nomb.empty() && !num.empty() && !por.empty())
		{
			int x = stoi(por); int y = stoi(num);
			t = new RestriccionTransporte(cod, nomb, y);
			t->setPorcentaje(x); t->getTamDisponible();
			lt->agregar(t);
		}

	}
	entrada.close();
}

void Archivo::cargarDatosRuta(ListaRuta* lr,string nom, ListaTransporte* lt)
{
	string cod, nomb; 
	Ruta* r;

	ifstream entrada(nom);

	if (!entrada) {

		throw entrada;
		entrada.close();
	}

	while (!entrada.eof()) {

		getline(entrada, cod, '\t');
		getline(entrada, nomb, '\n');         

		if (!cod.empty() && !nomb.empty()) {
			r = new Ruta(cod, nomb);
			lr->agregar(r);

		}


	}
	entrada.close();
}

void Archivo::cargarDatosRutaBuses(ListaRuta* lr, string nom, ListaTransporte* lt)
{
	string cod, nomb, codaux;
	Ruta* r; Transporte* t;

	ifstream entrada("ListaRBus.txt");

	if (!entrada) {

		throw entrada;
		entrada.close();
	}

		getline(entrada, cod, '\n');

		if (!cod.empty() ) {

			r = lr->busqueda(cod);

			while (!entrada.eof()) {

				getline(entrada, codaux, '\n');

				if (!codaux.empty()) {

					t = lt->busqueda(codaux);

					if (t == NULL) {
						r = lr->busqueda(codaux);
					}
					else {
						r->insertarTransporte(t);
					}

				}

			}

		}

	entrada.close();

}

void Archivo::crearArchivos(string nomR, string nomT,string nomRT)
{
	ofstream fAux;
	fAux.open(nomR, ios::out | ios::app);
	fAux.close();
	ofstream fAux2;
	fAux2.open(nomT, ios::out | ios::app);
	fAux2.close();
	ofstream fAux3;
	fAux3.open(nomRT, ios::out | ios::app);
	fAux3.close();
}
