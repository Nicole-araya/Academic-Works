#ifndef DINERO_H
#define DINERO_H
#include <iostream>
#include <sstream>

using namespace std;
class Dinero
{
    public:
        Dinero(int,int);
        virtual ~Dinero();

        int getValor();
        int getcan();
        void setCan(int);


    protected:
        int valor;
        int can;


};

#endif // DINERO_H


class Quinientos:public Dinero{

public:

    Quinientos(int,int);

~Quinientos();

};


class Cien:public Dinero{

public:

    Cien(int,int);
~Cien();


};

class Cincuenta:public Dinero{

public:

    Cincuenta(int,int);
~Cincuenta();


};
