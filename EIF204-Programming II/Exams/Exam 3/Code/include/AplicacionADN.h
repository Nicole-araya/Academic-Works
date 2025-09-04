#pragma once
#include<fstream>
#include "ContEnfermedades.h"
#include "ContPacientes.h"
#include "IReporte.h"

using namespace std;

class AplicacionADN {
    private:
        ContPacientes* cp;
        ContEnfermedades* ce;
    public:
        AplicacionADN();
        virtual ~AplicacionADN();
        ContPacientes* getContenPacientes();
        ContEnfermedades* getContenEnfermedades();
        void cargarPacientes();
        void cargarEnfermedades();
        void reporte(IReporte*);
        // No necesarios para el examen..
        void verPacientesEnPantalla();
        void verEnfermedadesEnPantalla();
};

