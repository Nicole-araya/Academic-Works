#pragma once
#include <iostream>
using namespace std;


class Carro
{

private:

	int ruedas;

public:

	Carro(int);
	~Carro();
	int virtual rueda();


};

////////////////////////////////////////// -----AQUI SE PUEDE VER DONDE SE DIVIDE LA FUNCIONALIDAD

class CarroElectrico
{

private:

	string motorElect;

public:

	CarroElectrico(string);
	~CarroElectrico();
	string virtual motorElec();


};

//////////////////////////////////////////  ----AQUI SE PUEDE VER DONDE SE DIVIDE LA FUNCIONALIDAD
class CarroGas
{

private:

	string motorGas;

public:

	CarroGas(string);
	~CarroGas();
	string virtual motorGaso();


};

//////////////////////////////////////////////////////////////////////  ----------CLASES HIJAS QUE HEREDAN LO QUE USARAN DE SUS PADRES------------


class Tesla : public Carro, CarroElectrico {

public:

	Tesla(int, string);
	~Tesla();
	int rueda();
	string motorElec();
	void imprimirInfo();

};


//////////////////////////////////////////////////

class Hyundai : public Carro, CarroGas {

public:
	Hyundai(int, string);
	~Hyundai();
	int rueda();
	string motorGas();

	void imprimirInfo();


};