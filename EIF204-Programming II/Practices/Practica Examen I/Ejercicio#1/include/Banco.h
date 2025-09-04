#ifndef BANCO_H
#define BANCO_H
#include "ListaCuenta.h"

class Banco
{
    public:
        Banco();
        virtual ~Banco();

        void menu();

        void ingresarCuenta(Cuenta*);


    private:
        ListaCuenta* lc;
};

#endif // BANCO_H
