#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuenta.h"

class CuentaCorriente: public Cuenta
{
    public:
        CuentaCorriente(int,string,float);
        virtual ~CuentaCorriente();

        void retirar(float);
         string toString();

};

#endif // CUENTACORRIENTE_H
