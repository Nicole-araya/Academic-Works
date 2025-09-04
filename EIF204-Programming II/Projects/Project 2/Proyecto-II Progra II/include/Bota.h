#pragma once
#include "ZapatoAbstracto.h"
class Bota :
    public ZapatoAbstracto{
public:

	Bota(string, double, string, bool);
	~Bota();
	string toString();
};

