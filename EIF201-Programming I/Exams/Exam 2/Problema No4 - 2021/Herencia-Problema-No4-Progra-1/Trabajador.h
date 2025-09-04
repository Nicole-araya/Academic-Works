#pragma once
#include"Persona.h"

class Trabajador : public Persona {
   protected:
	   int* vecEdadesHijos;
	   int numHijos;
	   int can;
   public:
	   Trabajador(string, string, int);
	   virtual ~Trabajador();
	   void llenarVecDeEdades(int);
	   string toString() const;
};
