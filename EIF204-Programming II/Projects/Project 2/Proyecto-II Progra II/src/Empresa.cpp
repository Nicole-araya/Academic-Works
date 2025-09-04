#include "Empresa.h"

Empresa::Empresa(string cedula, string nom, string correo, double pago, string ciudad, string pais, bool frecuente) : Cliente(cedula, nom, correo, pago, ciudad, pais)
{
	clienteFrecuente = frecuente;
}

Empresa::~Empresa()
{
}

bool Empresa::getFrecuencia()
{
	return clienteFrecuente;
}

void Empresa::actualizar(bool mensaje)
{
	cout << ">>>Empresa " << nombre << endl;
	mensaje ? cout << "Se le notifica que se ha ingresado un traje nuevo en la tienda" << endl :
		cout << "Se le notifica que se ha eliminado un traje en la tienda" << endl;

}


string Empresa::toString()
{
	stringstream s;

	s << "Empresa " << nombre << " Cedula juridica: " << cedula << endl;
	s << "Cliente frecuente: "; clienteFrecuente ? s << " SI " : s << " NO ";
	s << endl<< "Correo " << correo << ", Localidad: " << ciudad << ", " << pais << endl
		<< "Pago de subcripcion --> " << pagoSubscripcion << endl;

	return s.str();
}
