#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Cliente{
private:
	string nombre;
	string id;
	bool ninio;
	bool embarazada;
	bool mayor;
	int categoria;

	int influencia;
	//falta sobrecarga de operador <<;
public:
	Cliente(string nombre, string id, bool nin, bool emba, bool mayor, int cat);
	Cliente();
	void setNombre(string nombre);
	void setID(string id);
	void setInfluencia(int inf);

	string getNombre();
	string getID();
	int getInfluencia();

	void guardar(ofstream& salida);

	friend ostream& operator << (ostream& ss, const Cliente& c);
	bool operator < ( const Cliente& c);
	friend bool operator > (const Cliente& c,const Cliente& p);
};

