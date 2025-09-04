#pragma once
#include"Trabajador.h"

class AdmUniversitario : public Trabajador {
  private:
    string titulo;
    int aniosLaborales;
  public:
    AdmUniversitario(string, string, int, string, int);
    virtual ~AdmUniversitario();
    string toString() ;
};
