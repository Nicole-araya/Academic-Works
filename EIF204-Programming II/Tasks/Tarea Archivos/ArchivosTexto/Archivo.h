#pragma once
#include <iostream>
#include  <fstream>
#include <string>
using namespace std;

class Archivo
{
private:
    string nombre;

public:
    Archivo(string);
    ~Archivo();
    void setNom(string);
    string getNom();


};
