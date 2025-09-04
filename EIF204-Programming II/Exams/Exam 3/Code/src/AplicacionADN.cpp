#include "AplicacionADN.h"

AplicacionADN::AplicacionADN() {
    cp = new ContPacientes;
    ce = new ContEnfermedades();
}

AplicacionADN::~AplicacionADN() {
    if (cp != NULL) delete cp;
    if (ce != NULL) delete ce;
}

ContPacientes* AplicacionADN::getContenPacientes() {
    return cp;
}

ContEnfermedades* AplicacionADN::getContenEnfermedades() {
    return ce;
}

void AplicacionADN::cargarPacientes() {

    ifstream entrada("Pacientes.txt");


    cp->recuperaPacientes(entrada);

    entrada.close();
}

void AplicacionADN::cargarEnfermedades() {

    ifstream entrada("Enfermedades.txt");


    ce->recuperaEnfermedades(entrada);

    entrada.close();
}

void AplicacionADN::reporte(IReporte* irep) {

    irep->encabezado();

    for (int i = 0; i < cp->getCantidad(); i++) {

        irep->analisis(cp->obtPacienteEnPos(i), ce);

    }
   

}

// No necesarios para el examen..

void AplicacionADN::verPacientesEnPantalla() {
    cout << cp->toString() << endl;
}

void AplicacionADN::verEnfermedadesEnPantalla() {
    cout << ce->toString() << endl;
}

