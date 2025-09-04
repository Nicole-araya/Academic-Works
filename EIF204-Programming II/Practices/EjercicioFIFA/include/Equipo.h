#ifndef EQUIPO_H
#define EQUIPO_H
#include "FIFA.h"

class Equipo: public FIFA
{
    public:
        Equipo(string,string,string);
        virtual ~Equipo();
        string toString();

    protected:

    private:
        string nombre;
        string colorUniforme;
        string siglas;
};

#endif // EQUIPO_H
