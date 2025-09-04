#pragma once
#include "IReporte.h"
#include "InterfazUsuario.h"
using namespace std;

class RepAnalisis1 : public IReporte {
public:
    RepAnalisis1();
    virtual ~RepAnalisis1();
    void encabezado();
    void analisis(Paciente*,  ContEnfermedades*);
};

RepAnalisis1::RepAnalisis1() {}
RepAnalisis1::~RepAnalisis1() {}



void RepAnalisis1::encabezado() {
    InterfazUsuario::ventanaParaEncabezadoAnalisis1();
}



void RepAnalisis1::analisis(Paciente* p, ContEnfermedades* ce) {

    int repeticiones = 0;
    string textoBuscar = p->getSecuencia();
    Enfermedad* e = NULL;
    unsigned long index = 0;

    for (int i = 0; i < ce->getCantidad(); i++) {
       e= ce->obtEnfermedadEnPos(i);
       string textoBase = e->getSecEnfermedad();

       while ((index = textoBase.find(textoBuscar, index)) != std::string::npos) {
           index += textoBuscar.length();
          
           repeticiones++;


       }

       cout << "NO C";



    }
}
//-----------------------FIN DE LA CLASE RepAnalisis1------------------------

