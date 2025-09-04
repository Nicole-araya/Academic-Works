#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int d, int m, int a);
	virtual ~Fecha();
	int getDia();
	int getMes();
	int getAnio();
	string toString() const;
};
