#ifndef GERENTE_H
#define GERENTE_H
#include "Empleado.h"
#include "Salario.h"

class Gerente: public Empleado, Salario
{
    public:
        Gerente(string,string,int,string );
        virtual ~Gerente();
        void setArea(string);
        string getArea();
        string toString();

    protected:

        string area;


};

#endif // GERENTE_H
