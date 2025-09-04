#ifndef COLEGIOS_H
#define COLEGIOS_H
#include "OrganoEducativo.h"

class Colegios: public OrganoEducativo
{
    public:
        Colegios(string,string,string,string,int,string);
        virtual ~Colegios();
        string toString();

    protected:

         string numero;
        string direccion;
        string nomDirecto;
        int annio;
        string titulo;


};

#endif // COLEGIOS_H
