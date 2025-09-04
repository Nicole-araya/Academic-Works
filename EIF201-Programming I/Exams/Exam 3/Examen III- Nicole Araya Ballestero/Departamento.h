#pragma once
#include"Empleado.h"

class Departamento {
   private:

	  int codigo;
	  string descripcion;
	  Empleado** vec;
	  int can;
	  int tam;

   public:
	  Departamento(int val);
	  virtual ~Departamento();
	  bool ingresaEmpleado(Empleado* emp);

	  Empleado* buscar(int);

	  string toString() const;
	  void setDescripcion(string);
	  void setCodigo(int);
	  int getCan();
	  string getDescripcion();
	  int getCodigo();
	  bool empleadoYaExiste(int cod);

	  string reportarEmpleados();
	  string reportarMismoDia(Fecha*);

	  void EliminarPuesto(Empleado*);
	  string imprimirEmpleados();
	  


	  string reporteSalario();
	  double sumaSalario();

	  Empleado* mayorSalario();


};