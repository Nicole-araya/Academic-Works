#pragma once
#include <sstream>
#include <iostream>
#include<fstream>
using namespace std;

#define DELIMITA_CAMPO //...
#define DELIMITA_REGISTRO //...

class Enfermedad {
private:
	string nombreEnferm;
	string secEnferm;

public:
	Enfermedad(string = "", string = "");
	virtual ~Enfermedad();
	string getNombEnfermedad();
	string getSecEnfermedad();
	string toString();
	static Enfermedad* recuperaEnfermedad(istream&);
};

