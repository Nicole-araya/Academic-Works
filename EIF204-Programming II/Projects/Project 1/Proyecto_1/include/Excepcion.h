#pragma once
#include <iostream>
#include <sstream> 
using namespace std;
class Excepcion
{
public:

	 static string excepcion();
};

class NotFound :public Excepcion {

public:

	static string excepcion();

};

class Found :public Excepcion {

public:

	static string excepcion();

};

class LetterOption :public Excepcion {

public:

	static string excepcion();

};

class NotAvaible :public Excepcion {

public:

	static string excepcion();

};

class Downloading :public Excepcion {

public:

	static string excepcion();

};

class Existence :public Excepcion {

public:

	static string excepcion();

};