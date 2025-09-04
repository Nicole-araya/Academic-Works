#include "Archivo.h"

void Archivo::cargarDatos(ArbolAVL<Cliente>* arbol, string nom)
{
	string id, nomb, ninio, embarazada,mayor,categoria;
	bool n, e, m;
	Cliente* c;
	ifstream entrada(nom);

	if (!entrada) {

		throw entrada;
		entrada.close();
		return;
	}

	while (!entrada.eof()) {

		getline(entrada, nomb, ',');
		getline(entrada, id, ',');
		getline(entrada, ninio, ',');
		getline(entrada, embarazada, ',');
		getline(entrada, mayor, ',');
		getline(entrada,categoria, '\n');

		if (!nomb.empty() && !id.empty() && !mayor.empty() && !categoria.empty())  //BORRAR A FUTURO, le falta todos los parametros
		{
			int ca = stoi(categoria); 
			n = ninio == "Yes";
			e = embarazada == "Yes";
			m = mayor == "Yes";

			 c= new Cliente(nomb,id,n, e,m,ca);

			long long i; stringstream ss;  ss << c->getID(); ss >> i;
			 arbol->insertar(c, i);

		}

	}
	entrada.close();
}
