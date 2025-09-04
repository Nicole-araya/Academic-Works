#pragma once
#include "PantalonAbstracto.h"
class Pantaloneta :
    public PantalonAbstracto{
public:

	Pantaloneta(string, double, string, bool);
	~Pantaloneta();
	string toString();
};

