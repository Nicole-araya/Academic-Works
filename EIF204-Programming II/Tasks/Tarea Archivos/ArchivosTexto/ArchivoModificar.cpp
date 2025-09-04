#include "ArchivoModificar.h"

ArchivoModificar::ArchivoModificar()
{
}

ArchivoModificar::~ArchivoModificar()
{
}

void ArchivoModificar::modificar(string nom, string contenido)
{
    ofstream salida(nom, ios::out);

    salida << contenido;

    salida.close();
}
