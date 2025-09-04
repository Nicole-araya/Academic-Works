#pragma once
#include<iostream>
#include<sstream>
#include"Departamento.h"
using namespace std;

class Tienda {   // La Tienda viene siendo como un Contenedor de Departamentos.
    private:
	   string nombreTienda;
	   string cedulaJuridica;
	   //--------------------
	   Departamento** vec;
	   int can;
	   int tam;

    public:

	   Tienda(int);    // Ingresar el número de departamentos.
	   virtual ~Tienda();

	   void setNombreTienda(string);
	   void setCeduJuridica(string);
	   string getNombreTienda();
	   string getCedulaJuridica();
	   int getCantidad();
	   int getTamanio();
	   bool  ingresaDepartamento(Departamento* dep);
	   Departamento* buscar(int);
	   string toString() const;
	   bool tiendaYaExiste(int );
	   Empleado* buscarEmpleado(int);
	   string imprimirEmpleadosT();

	   string imprimirMismoDia(Fecha*);

	   string imprimirSalario();
	   string imprimirMayorSalario();

};




