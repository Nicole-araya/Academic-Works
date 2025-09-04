#pragma once
#include"Empleado.h"


class Cajero : public Empleado {
   private:
	   int horasTrabajadas;
	   double salarioXhora;
   public:
	   Cajero(int = 0, string = "", string = "",Fecha* = NULL, int = 0, double = 0.0);
	   virtual ~Cajero();
	   virtual int getHorasTrabajadas();
	   virtual double getSalarioXHora();
	   virtual void setHorasTrabajadas(int);
	   virtual void setSalarioXHora(double);

	   virtual double salario();
	   virtual string toString() const;
	   virtual string imprimirEmpleadoSalario();
};
