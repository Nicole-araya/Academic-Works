#pragma once
#include "Tripulante.h"
#include <fstream>

class Piloto :
    public Tripulante
{
private:

    string correo;
    char sexo;

public:

    Piloto(string, string, int, string, char);
    ~Piloto();

    void setCorreo(string);
    void setSexo(char);
    string getCorreo();
    char getSexo();

    void guardar(ofstream& );
    string toStringPiloto();
};

