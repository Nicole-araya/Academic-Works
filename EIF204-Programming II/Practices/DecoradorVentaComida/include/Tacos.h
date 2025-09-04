#ifndef TACOS_H
#define TACOS_H
#include "Decorador.h"

class Tacos: public Decorador
{
    public:
        Tacos(VentaComida*);
        virtual ~Tacos();
          virtual string  descripcion();
       virtual double precio();

    protected:

    private:
};

#endif // TACOS_H
