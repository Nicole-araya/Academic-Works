#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Habitacion {
   private:
	   int numHabitacion;  // El numero de habitación va desde 1, hasta el 24.
	   int numCamasAdult;  // Tiene dos (2) camas para adulto
	   int numCamasNinos;  // Tiene tres (3) camas para niños
	   char estado;        // O = Ocupado   D = Desocupado    M = Mantenimiento.
	   bool desc;          // desc (true/false) Si true, se debe aplicar 50% de descuento a las camas de niños.
   public:
	   Habitacion();
	   virtual ~Habitacion();
	   void setNumHabitacion(int);
	   void setEstado(char);
	   void setDesc(bool);

	   int getNumHabitacion();
	   char getEstado();
	   bool getDesc();
	   string toString() const;
};