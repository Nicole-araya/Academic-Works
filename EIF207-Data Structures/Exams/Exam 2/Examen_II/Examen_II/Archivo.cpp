#include "Archivo.h"

void Archivo::cargarDatos(Graph<char,double>* gd, GraphK<char, double>* gk, string nom)
{
	string maq1, maq2,peso; 
	ifstream entrada(nom);

	if (!entrada) {

		throw entrada;
		entrada.close();
		return;
	}

	while (!entrada.eof()) {

		getline(entrada, maq1, ',');
		getline(entrada, maq2, ',');
		getline(entrada, peso, '\n');

		if (!maq1.empty() && !maq2.empty() && !peso.empty() )
		{
			double p=0.0; stringstream ss;  ss << peso; ss >> p;
			gd->addEdge(maq1[0], maq2[0], p);
			gk->addEdge(maq1[0], maq2[0], p);
		}
	}
	entrada.close();
}
