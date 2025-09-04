#ifndef FACTURA_H
#define FACTURA_H
#include "VentaComida.h"

class Factura: public VentaComida
{
    public:
        Factura();
        virtual ~Factura();
         virtual string  descripcion();
       virtual double precio();

    protected:

    private:
};

#endif // FACTURA_H
