#ifndef BEBIDA_H
#define BEBIDA_H
#include "Decorador.h"

class Bebida: public Decorador
{
    public:
        Bebida(VentaComida*);
        virtual ~Bebida();
        virtual string  descripcion();
       virtual double precio();

    protected:

    private:
};

#endif // BEBIDA_H
