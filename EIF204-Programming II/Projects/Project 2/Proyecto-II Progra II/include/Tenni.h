#pragma once
#include "ZapatoAbstracto.h"
class Tenni : public ZapatoAbstracto{
public:

	Tenni(string, double, string, bool);
	~Tenni();
	string toString();
};

