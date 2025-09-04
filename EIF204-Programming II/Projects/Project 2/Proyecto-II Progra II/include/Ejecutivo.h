#pragma once
#include "ZapatoAbstracto.h"
class Ejecutivo : public ZapatoAbstracto{
public:

	Ejecutivo(string, double, string, bool);
	~Ejecutivo();
	string toString();
};

