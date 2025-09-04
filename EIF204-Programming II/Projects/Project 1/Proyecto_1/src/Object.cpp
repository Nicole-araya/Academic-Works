#include "Object.h"

Object::Object(string i):identificador(i)
{
}

Object::~Object()
{
}

string Object::getIdentificador()
{
	return identificador;
}

void Object::setIdentificador(string i)
{
	identificador = i;
}
