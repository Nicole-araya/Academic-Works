#pragma once
#include "Sala.h"
#include "Pelicula.h"

class Funcion{

private:

	string fecha;
	string hora;
	Sala* sala;
	Pelicula* pelicula;



public:

	Funcion( string, string, Sala* , Pelicula* );
	~Funcion();

	void setFecha(string);
	void setHora(string);
	void setSala(Sala*);
	void setPelicula(Pelicula* );

	string getFecha();
	string getHora();
	Sala* getSala();
	Pelicula* getPelicula();

	string toString();


};

