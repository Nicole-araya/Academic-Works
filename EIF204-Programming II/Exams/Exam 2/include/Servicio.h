#ifndef SERVICIO_H
#define SERVICIO_H
#include <sstream>
#include <iostream>
#include<string>
using namespace std;
class Servicio
{
    public:

 static string nombreDelGrupo(int);
  static double getPresupuesto(int);
  static int getActivPorAnio(int);
  static int getCantidadAsociados(int);

};

#endif // SERVICIO_H
