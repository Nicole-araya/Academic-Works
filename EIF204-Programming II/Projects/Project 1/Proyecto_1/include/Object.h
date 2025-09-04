#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Object
{
protected:

	string identificador;

public:

	Object(string);
	~Object();

	string getIdentificador();
	void setIdentificador(string);

	virtual string toString() = 0;



};

