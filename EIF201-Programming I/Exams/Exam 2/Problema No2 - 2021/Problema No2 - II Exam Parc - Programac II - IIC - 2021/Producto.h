#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Producto {
   private:
	  string nombreP;
	  double precioP;
   public:
	  Producto(string = "", double = 0.0);  
	  virtual ~Producto();
	  string getNombreP();
	  double getPrecioP();
	  string toString();
	  bool esIgualA(Producto&);
};

