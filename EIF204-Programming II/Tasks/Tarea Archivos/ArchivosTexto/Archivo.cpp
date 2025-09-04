#include "Archivo.h"

Archivo::Archivo(string nom)
{
    nombre = nom;
}

Archivo::~Archivo()
{
 
}
void Archivo::setNom(string nom) {
    nombre = nom;

}

string Archivo::getNom() {
    return nombre;
}