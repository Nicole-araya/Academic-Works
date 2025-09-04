#pragma once
#include"CategTrabajador.h"
#include"Fecha.h"
#include <sstream>
#include <iostream>

class Empleado {
   protected:
	   int ID;
	   string nombre;
	   string categoria;
	   Fecha* fecha;
   public:
	   Empleado(int = 0, string = "", string = "", Fecha* = NULL);
	   virtual ~Empleado();
	   virtual int    getID();
	   virtual string getNombre();
	   virtual string getCategoria();
	   virtual Fecha* getFecha();
	   virtual void   setID(int);
	   virtual void   setNombre(string);
	   virtual void   setCategoria(string);
	   virtual void   setFecha(Fecha*);

	   virtual double salario();

	   virtual string toString() const;

	   virtual string imprimirEmpleadoSalario();

	   virtual bool   esIgualA(Empleado);
};