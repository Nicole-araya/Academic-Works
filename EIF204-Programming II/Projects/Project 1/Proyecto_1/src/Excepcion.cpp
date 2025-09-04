#include "Excepcion.h"


string Excepcion::excepcion()
{
	return "";
}

string NotFound::excepcion()
{
	stringstream s;

	s << "No se encuentra lo digitado..." << endl;

	return s.str();
}

string Found::excepcion()
{
	stringstream s;

	s << "Ya se encuentra..." << endl;

	return s.str();
}

string LetterOption::excepcion()
{
	stringstream s;

	s << "Ha ingresado una letra..." << endl;

	return s.str();
}



string NotAvaible::excepcion()
{
	stringstream s;

	s << "No hay cupo para la cantidad deseada..." << endl;

	return s.str();
}

string Downloading::excepcion()
{
	stringstream s;

	s << "No se pudo cargar los archivos..." << endl;

	return s.str();
}

string Existence::excepcion()
{
	stringstream s;

	s << "Ya se encuentras siendo usado en otra ruta"<< endl;

	return s.str();
}
