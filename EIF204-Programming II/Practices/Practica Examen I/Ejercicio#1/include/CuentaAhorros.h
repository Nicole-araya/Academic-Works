#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "Cuenta.h"

class CuentaAhorros: public Cuenta
{
    public:
        CuentaAhorros(int,string,float,string);
        virtual ~CuentaAhorros();

        string getBeneficiario();
        void retirar(float);
         string toString();

    private:

        string beneficiario;


};

#endif // CUENTAAHORROS_H
