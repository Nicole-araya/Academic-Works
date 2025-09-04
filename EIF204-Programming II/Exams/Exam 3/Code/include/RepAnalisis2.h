#pragma once
#include "IReporte.h"
#include "InterfazUsuario.h"
using namespace std;

class RepAnalisis2 : public IReporte {
public:
    RepAnalisis2();
    virtual ~RepAnalisis2();
    void encabezado();
    void analisis(Paciente*, ContEnfermedades* co);
};

RepAnalisis2::RepAnalisis2() {}
RepAnalisis2::~RepAnalisis2() {}

void RepAnalisis2::encabezado() {
    InterfazUsuario::ventanaParaEncabezadoAnalisis2();
}

void RepAnalisis2::analisis(Paciente* p, ContEnfermedades* co) {



    string textoBase = p->getSecuencia();
    string textoBuscar; int varA=0, varT=0, varC=0, varG=0,total=0;
    Enfermedad* e = NULL;
    int repeticiones = 0,num;
    unsigned long index = 0;

    for (int i = 0; i < 3; i++) {

        if (i == 0) { textoBuscar = "A"; }
        if (i == 1) { textoBuscar = "C"; }
        if (i == 2) { textoBuscar = "T"; }
        if (i == 3) { textoBuscar = "G"; }

        for (int i = 0; i < textoBase.size();i++) {

            if (textoBase[i] == textoBuscar[0]) {
                repeticiones++;
            }
        }
        if (i == 0) { varA = repeticiones;  repeticiones = 0; }
        if (i == 1) { varC = repeticiones;  repeticiones = 0; }
        if (i == 2) { varT=repeticiones;  repeticiones = 0; }
        if (i == 3) { varG = repeticiones; repeticiones = 0; }
    }

    total = varA + varC + varG + varT;

    cout << p->getNombre() << " [ A - " << varA * 100 / total << "%, C - " << varC * 100 / total << "%, T - " << varT * 100 / total << "%, G - " << varG * 100 / total << "%" << endl;

}
//-----------------------FIN DE LA CLASE RepAnalisis2------------------------


