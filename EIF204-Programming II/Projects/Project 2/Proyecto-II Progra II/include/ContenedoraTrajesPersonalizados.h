#pragma once
#include <list>
#include "TrajeAbstracto.h"
#include "GuardarDatos.h"
#include <sstream>
class ContenedoraTrajesPersonalizados
{
private:
    list <TrajeAbstracto*> traje;

public:
    ~ContenedoraTrajesPersonalizados();
    bool ingresaTraje(TrajeAbstracto* t);
    TrajeAbstracto* buscaPorCod(string codigo);
    string toString();

    int contador();

    void guardarDatos(string nombre);
};

