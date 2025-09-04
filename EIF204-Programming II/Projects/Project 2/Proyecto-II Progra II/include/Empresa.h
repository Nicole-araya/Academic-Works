#pragma once
#include "Cliente.h"
class Empresa :
    public Cliente{
private:
    bool clienteFrecuente;

public:
    Empresa(string cedula, string nom, string correo, double pago, string ciudad, string pais, bool frecuente);
    ~Empresa();
    bool getFrecuencia();
    void actualizar(bool);
    string toString();
};

