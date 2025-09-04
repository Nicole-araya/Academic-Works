#pragma once
#include <sstream>
#include <iostream>
using namespace std;
class Observa {

public:

	Observa(){}
	virtual ~Observa(){}
	virtual void actualizar(bool) = 0;
	virtual string toString() = 0;

};