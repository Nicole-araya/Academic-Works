#pragma once
#ifndef RECIPIENTE_H
#define RECIPIENTE_H
#include "Dinero.h"

class Recipiente
{
public:
    Recipiente(string);
    virtual ~Recipiente();
    void virtual insertarDinero(Dinero*) = 0;

    virtual Dinero* buscar(int) = 0;


protected:

    string nombre;
    Dinero** v;
    int tam;
    int can;


};

#endif // RECIPIENTE_H


class Vuelto : public Recipiente {


public:
    Vuelto(string);
    virtual ~Vuelto();
    void insertarDinero(Dinero*);
    Dinero* buscar(int);
    void darVuelto(int);

};


class Recibir : public Recipiente {


public:
    Recibir(string);
    virtual ~Recibir();
    void insertarDinero(Dinero*);

    void recibirDinero(int);
    Dinero* buscar(int);


};
