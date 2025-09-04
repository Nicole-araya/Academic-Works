#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
#include <sstream>

using namespace std;
class Cuenta
{
    public:
        Cuenta(int,string,float);
        virtual ~Cuenta();

        int getNumCuenta();
        string getNombre();
        float getSaldo();

        void consignar(float);

        void virtual retirar(float)=0;

        virtual string toString()=0;

    protected:
        int numCuenta;
        string nombre;
        float saldo;



};

#endif // CUENTA_H
