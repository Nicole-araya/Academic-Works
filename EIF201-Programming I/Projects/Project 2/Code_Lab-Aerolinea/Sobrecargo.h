#pragma once
#include "Tripulante.h"
#include <fstream>

class Sobrecargo :
    public Tripulante
{
private:
    string titulo;
    string telefono;
    int grado;

public:

    Sobrecargo(string, string, int,string,string,int);
    ~Sobrecargo();

    void setTitulo(string);
    void setTelefono(string);
    void setGrado(int);
    string getTitulo();
    string getTelefono();
    int getGrado();

    void guardar(ofstream&);
    string toString();
};

