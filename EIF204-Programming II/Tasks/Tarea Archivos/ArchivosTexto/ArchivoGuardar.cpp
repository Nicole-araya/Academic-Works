#include "ArchivoGuardar.h"

ArchivoGuardar::ArchivoGuardar()
{
    //ctor
}

ArchivoGuardar::~ArchivoGuardar()
{
    //dtor
}

void ArchivoGuardar::guardar(Archivo* a, string contenido) {

    ofstream salida(a->getNom());

    salida << contenido;

    salida.close();

}