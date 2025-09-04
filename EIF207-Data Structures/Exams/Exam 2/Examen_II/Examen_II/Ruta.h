#pragma once
#include <sstream>
#include <fstream>
using namespace std;
class Ruta
{
private:
	char maq1;
	char maq2;
	int concreto;
	int gypsum;
	int cambPiso;
	int adicional;

public:
	Ruta(char m1, char m2, int c, int g, int cp, int a);
	~Ruta();
	double calcularPeso(int v, int n, double pe);
	double calcular();
	void guardar(ofstream& salida);
	string toString();
};

