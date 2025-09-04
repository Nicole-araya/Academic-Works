#ifndef HAMBURGUESA_H
#define HAMBURGUESA_H
#include "Decorador.h"

class Hamburguesa: public Decorador
{
    public:
        Hamburguesa(VentaComida*);
        virtual ~Hamburguesa();
        virtual string  descripcion();
       virtual double precio();

    protected:

    private:
};

#endif // HAMBURGUESA_H
