#include "Persona.h"

Persona::Persona(string cedula, string nom, string correo, double pago, string ciudad, string pais, string nacionalidad): Cliente(cedula,nom,correo,pago,ciudad,pais)
{
	this->nacionalidad = nacionalidad;

}

Persona::~Persona()
{
}

void Persona::actualizar(bool mensaje)
{
	cout << ">>>Subscriptor " << nombre << endl;

	mensaje ? cout << "Se le notifica que se ha ingresado un traje nuevo en la tienda" << endl : 
				cout << "Se le notifica que se ha eliminado un traje en la tienda" << endl;
	
}

string Persona::toString() {

	stringstream s;

	s << "Subcriptor " << nombre << " ID " << cedula << " Nacionalidad: " << nacionalidad << endl
		<< "Correo " << correo << ", Localidad: " << ciudad << ", " << pais << endl
		<< "Pago de subcripcion --> " << pagoSubscripcion << endl;

	return s.str();
}

string Persona::getNacionalidad()
{
	return nacionalidad;
}
