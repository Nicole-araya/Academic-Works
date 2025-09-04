#pragma once
#include "PantalonAbstracto.h"
class DeVestir :
    public PantalonAbstracto{
public:

	DeVestir(string, double, string, bool);
	~DeVestir();
	string toString();
};

