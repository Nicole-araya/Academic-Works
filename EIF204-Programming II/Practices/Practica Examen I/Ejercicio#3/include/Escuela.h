#ifndef ESCUELA_H
#define ESCUELA_H
#include "OrganoEducativo.h"

class Escuela: public OrganoEducativo
{
    public:
        Escuela(string,string,string,string,int,int);
        virtual ~Escuela();
        string toString();


    protected:
        string numero;
        string direccion;
        string nomDirecto;
        int annio;
        int cantidad;


};

#endif // ESCUELA_H
