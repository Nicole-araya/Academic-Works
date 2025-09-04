#ifndef PAPASFRITAS_H
#define PAPASFRITAS_H
#include "Decorador.h"

class PapasFritas: public Decorador
{
    public:
        PapasFritas(VentaComida*);
        virtual ~PapasFritas();
          virtual string  descripcion();
       virtual double precio();

    protected:

    private:
};

#endif // PAPASFRITAS_H
