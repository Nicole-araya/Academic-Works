#include "Carro.h"

Carro::Carro(int r)
{
	ruedas = r;
}

Carro::~Carro()
{
}

int Carro::rueda()
{
	return ruedas;
}

////////////////////////////////////////////////////////////////

CarroElectrico::CarroElectrico(string me)
{
	motorElect = me;
}

CarroElectrico::~CarroElectrico()
{
}

string CarroElectrico::motorElec()
{
	return motorElect;
}

////////////////////////////////////////////////////////////////

CarroGas::CarroGas(string mg)
{
	motorGas = mg;
}

CarroGas::~CarroGas()
{
}

string CarroGas::motorGaso()
{
	return motorGas;
}

////////////////////////////////////////////////////////////////

Tesla::Tesla(int r, string m): Carro(r),CarroElectrico(m)
{
}

Tesla::~Tesla()
{
}

int Tesla::rueda()
{
	return Carro::rueda();
}

string Tesla::motorElec()
{
	return CarroElectrico::motorElec();
}

void Tesla::imprimirInfo()
{
	cout << "Tiene " << Carro::rueda() << " ruedas" << endl;
	cout << "Y un " << CarroElectrico::motorElec() << endl << endl;
}

////////////////////////////////////////////////////////////////

Hyundai::Hyundai(int r,string m) : Carro(r), CarroGas(m)
{
}

Hyundai::~Hyundai()
{
}

int Hyundai::rueda()
{
	return Carro::rueda();
}

string Hyundai::motorGas()
{
	return CarroGas::motorGaso();
}

void Hyundai::imprimirInfo()
{
	cout << "Tiene " << Carro::rueda() << " ruedas" << endl;
	cout << "Y un " << CarroGas::motorGaso() << endl << endl;
}
