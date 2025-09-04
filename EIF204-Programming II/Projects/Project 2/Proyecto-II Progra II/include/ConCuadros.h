#pragma once
#include "CamisaAbstracta.h"
class ConCuadros: public CamisaAbstracta{
public:

	ConCuadros(string codigo, double precio, string color, bool tam);
	~ConCuadros();
	string toString();
};

