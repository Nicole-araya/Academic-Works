#pragma once
#include <iostream>
using namespace std;

class Metal
{
private:
    string nombre;
    string simbolo;

public:
    Metal(string = "-");
    virtual ~Metal();
    string virtual imprimirSimbolo();

};

///////////////////////////////////////////////////////////

class Hierro : public Metal
{

public:
    Hierro(string);
    virtual ~Hierro();
    string imprimirSimbolo();


};

///////////////////////////////////////////////////////

class Plata : public Metal
{

public:
    Plata(string);
    virtual ~Plata();
    string imprimirSimbolo();


};

///////////////////////////////////////////////////////

class Oro : public Metal
{

public:
    Oro(string);
    virtual ~Oro();
    string imprimirSimbolo();


};