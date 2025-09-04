#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Persona {
   protected:
	  string cedula;
	  string nombre;
   public:
	  Persona(string, string);
	  virtual ~Persona();
	  virtual string toString()=0;
};