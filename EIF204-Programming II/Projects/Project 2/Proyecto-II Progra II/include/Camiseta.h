#pragma once
#include "CamisaAbstracta.h"

class Camiseta : public CamisaAbstracta{

public:

	Camiseta(string, double, string, bool);
	~Camiseta();

	string toString();
};

