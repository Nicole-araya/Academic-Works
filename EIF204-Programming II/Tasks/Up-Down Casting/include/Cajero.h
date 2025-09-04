#ifndef CAJERO_H
#define CAJERO_H
#include "Empleado.h"
#include "Salario.h"

class Cajero: public Empleado, Salario
{
    public:
        Cajero(string,string,int,int);
        virtual ~Cajero();
        void setNumCaja(int);
        int getNumCaja();
        string toString();

    protected:
        int numCaja;

    private:
};

#endif // CAJERO_H
