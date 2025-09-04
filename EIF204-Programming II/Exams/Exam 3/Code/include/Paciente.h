#pragma once
#include<iostream>
#include<sstream>
#include <fstream>
using namespace std;

#define DELIMITA_CAMPO //...     
#define DELIMITA_REGISTRO //...   

class Paciente {
   private:
	 string id;
	 string nombre;
	 string telefono;
	 string correo;
	 string secuencia;
   public:
	   Paciente(string = "", string = "", string = "", string = "", string = "");
	   virtual ~Paciente();
	   string getId();
	   string getNombre();
	   string getTelefono();
	   string getCorreo();
	   string getSecuencia();
	   string toString();
	   static Paciente* recuperaPaciente(ifstream&);
};