#pragma once
#include "PantalonAbstracto.h"
class Jeans :
    public PantalonAbstracto{
public:

	Jeans(string, double, string, bool);
	~Jeans();
	string toString();
};

