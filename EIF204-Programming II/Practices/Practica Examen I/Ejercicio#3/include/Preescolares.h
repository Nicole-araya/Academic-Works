#ifndef PREESCOLARES_H
#define PREESCOLARES_H
#include "OrganoEducativo.h"

class Preescolares: public OrganoEducativo
{
    public:
        Preescolares(string,string,string,string);
        virtual ~Preescolares();
        string toString();

    protected:
        string numero;
        string direccion;
        string nomDirector;



};

#endif // PREESCOLARES_H
