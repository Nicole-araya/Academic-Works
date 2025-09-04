#pragma once
#include"Trabajador.h"

class ProfUniversitario : public Trabajador {
    private:
        bool propiedad;
        string gradoAcademico;
    public:
        ProfUniversitario(string, string, int, bool, string);
        virtual ~ProfUniversitario();
        string toString() ;
};