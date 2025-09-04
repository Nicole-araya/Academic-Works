#pragma once
#include "IReporte.h"
#include "InterfazUsuario.h"
using namespace std;

class RepAnalisis3 : public IReporte {
public:
    RepAnalisis3();
    virtual ~RepAnalisis3();
    void encabezado();
    void analisis(Paciente*, ContEnfermedades*);
};

RepAnalisis3::RepAnalisis3() {}
RepAnalisis3::~RepAnalisis3() {}

void RepAnalisis3::encabezado() {
    InterfazUsuario::ventanaParaEncabezadoAnalisis3();
}

void RepAnalisis3::analisis(Paciente* p,  ContEnfermedades* ce) {
    cout << "MATEMEN";
}


//-----------------------FIN DE LA CLASE RepAnalisis3------------------------


