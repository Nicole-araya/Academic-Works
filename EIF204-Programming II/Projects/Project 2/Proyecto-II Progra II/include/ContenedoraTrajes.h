#pragma once
#include <list>
#include "TrajeAbstracto.h"
#include "GuardarDatos.h"
#include <sstream>

class ContenedoraTrajes {
private:
    list <TrajeAbstracto*> traje;

public:
    ~ContenedoraTrajes();
    bool ingresaTraje(TrajeAbstracto* traje);
    bool eliminaTraje(TrajeAbstracto* traje);
    TrajeAbstracto* buscarTraje(TrajeAbstracto*);
    TrajeAbstracto* buscaPorCod(string codigo);
    string toString();

    void guardarDatos(string nombre);
};

