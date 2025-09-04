#include "ContenedoraTrajesPersonalizados.h"

ContenedoraTrajesPersonalizados::~ContenedoraTrajesPersonalizados()
{
	list<TrajeAbstracto*>::iterator it;
	for (it = traje.begin(); it != traje.end(); it++) {
		traje.erase(it);
	}
}

bool ContenedoraTrajesPersonalizados::ingresaTraje(TrajeAbstracto* t)
{
	if (t) {
		traje.push_back(t);

		return true;
	}

	return false;
}

TrajeAbstracto* ContenedoraTrajesPersonalizados::buscaPorCod(string codigo)
{
	list<TrajeAbstracto*>::iterator it;
	for (it = traje.begin(); it != traje.end(); it++) {

		if ((*it)->getCodigo() == codigo) {
			return *it;
		}
	}
	return NULL;
}

string ContenedoraTrajesPersonalizados::toString()
{
	stringstream ss;

	list<TrajeAbstracto*>::iterator it;
	ss << "--->> Trajes Personalizados <<----" << endl;
	ss << "==================================" << endl << endl;
	for (it = traje.begin(); it != traje.end(); it++) {

		ss << ">>>>" << (*it)->toString() << endl << endl;
	}
	return ss.str();
}

int ContenedoraTrajesPersonalizados::contador()
{
	return traje.size();
}

void ContenedoraTrajesPersonalizados::guardarDatos(string nombre)
{
	ofstream salida(nombre, ios::app);

	list<TrajeAbstracto*>::iterator it;
	for (it = traje.begin(); it != traje.end(); it++) {

		GuardarDatos::guardarTraje(salida, *it);
	}
	salida.close();
}
