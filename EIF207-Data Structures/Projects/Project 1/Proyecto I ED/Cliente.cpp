#include "Cliente.h"

Cliente::Cliente(string nombre, string id, bool nin, bool emba, bool mayor, int cat){
	this->influencia = 0;

	this->nombre = nombre;
	this->id = id;
	this->ninio = nin;
	this->embarazada = emba;
	this->mayor = mayor;
	this->categoria = cat;

	influencia = ninio * 20 + embarazada * 25 + this->mayor * 35;
	if(categoria == 1)influencia += 20;
	if(categoria == 2)influencia += 10;
	
}

Cliente::Cliente(){
	this->influencia = 0;

	this->nombre = "";
	this->id = "";
	this->ninio = 0;
	this->embarazada = 0;
	this->mayor = 0;
	this->categoria = 0;
}

void Cliente::setNombre(string nombre){
	this->nombre = nombre;
}

void Cliente::setID(string id){
	this->id = id;
}

void Cliente::setInfluencia(int inf){
	this->influencia = inf;
}

string Cliente::getNombre(){ return nombre; }

string Cliente::getID(){ return id; }

int Cliente::getInfluencia(){ return influencia; }

void Cliente::guardar(ofstream& salida)
{
	salida << nombre << ",";
	salida<<id << ",";
	ninio ? salida << "Yes" : salida << "No";
	salida << ",";
	embarazada ? salida << "Yes" : salida << "No";
	salida << ",";
	mayor ? salida << "Yes" : salida << "No";
	salida << ",";
	salida << categoria << "\n";
}

bool Cliente::operator<(const Cliente& c)
{
	return influencia<c.influencia;
}


ostream& operator<<(ostream& ss, const Cliente& c){
	ss << "\nCliente\n";
	ss << "-----------\n";
	ss << c.nombre << endl;
	ss << c.id << endl;
	ss << "%Prioridad: " << c.influencia << endl;
	ss << "Categoria: ";
	if(c.categoria==1)
	ss << "Premium" << endl;
	else if (c.categoria == 2)
		ss << "Oro" << endl;
	else
		ss << "Normal" << endl;

	return ss;
}

bool operator>(const Cliente& c, const Cliente& p){
	return c.influencia > p.influencia;;
}
