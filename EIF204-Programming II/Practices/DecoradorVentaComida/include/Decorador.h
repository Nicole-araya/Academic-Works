#ifndef DECORADOR_H
#define DECORADOR_H
#include "VentaComida.h"

class Decorador: public VentaComida
{
    public:
        Decorador(VentaComida*);
        virtual ~Decorador();
        virtual string  descripcion();
       virtual double precio();

    protected:

    private:
        VentaComida* comida;
};

#endif // DECORADOR_H
