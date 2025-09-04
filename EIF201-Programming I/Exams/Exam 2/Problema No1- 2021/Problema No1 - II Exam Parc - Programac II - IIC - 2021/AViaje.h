#pragma once
#include<iostream>
#include <sstream>
#include "Ruta.h"
using namespace std;

class AViaje {
    private:
	   string nombEmpresa;
	   string ceduJuridica;
	   string teleCelular;
    public:
	   AViaje(string ="", string="", string="");
	   virtual ~AViaje();
	   string getNombEmpresa();
	   string getCeduJuridic();
	   string getTeleCelular();
	   void setNombEmpresa(string);
	   void setCeduJuridic(string);
	   void setTeleCedular(string);
	   void infoDelViaje(int);
	   string toString() const;
};