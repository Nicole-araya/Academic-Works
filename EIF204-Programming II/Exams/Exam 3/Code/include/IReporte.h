#pragma once
#include "Paciente.h"
#include "ContEnfermedades.h"
using namespace std;
class IReporte {
    public:
        virtual void encabezado() = 0;

        virtual void analisis(Paciente* p, ContEnfermedades* ce) = 0;


        // C�digo de apoyo....
       /* virtual int AplicacionADNcalcularConcentracion(const string& textoBuscar, const string& textoBase) {
                    int repeticiones = 0;
                    unsigned long index = 0; // la posici�n donde se encuentra la letra
                    // El siguiente ciclo permite recorrer el string para identificar las veces que se
                    // repite un car�cter
                    while ((index = textoBase.find(textoBuscar, index)) != std::string::npos) {
                      index += textoBuscar.length();
                      repeticiones++;
                    }
                    return repeticiones;
        }*/
};


