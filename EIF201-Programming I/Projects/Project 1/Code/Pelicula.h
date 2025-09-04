#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Pelicula
{
private:
	string nombre;
	string genero;
	string tipo;
	string dimension;
	string tipoPublico;
	string sipnosis;


public:

	Pelicula(string, string, string, string, string, string);
	~Pelicula();

	void setNombre(string);
	void setGenero(string);
	void setTipo(string);
	void setDimension(string);
	void setTipoPublico(string);
	void setSipnosis(string);

	string getNombre();
	string getGenero();
	string getTipo();
	string getDimension();
	string getTipoPublico();
	string getSipnosis();

	string toString();

};

