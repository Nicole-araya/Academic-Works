#pragma once
#include"Persona.h"

class Estudiante : public Persona {
   private:
	   string carrera;
	   int edad;
   public:
	   Estudiante(string, string, string, int);
	   virtual ~Estudiante();
	   string toString() ;
};