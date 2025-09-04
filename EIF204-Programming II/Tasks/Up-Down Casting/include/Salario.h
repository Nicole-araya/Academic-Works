#ifndef SALARIO_H
#define SALARIO_H
#include <iostream>
#include <sstream>

using namespace std;

class Salario
{
    public:
        Salario(int);
        virtual ~Salario();
        int getSalario();

    protected:
        int saldo;
};

#endif // SALARIO_H


#ifndef SALARIO_COMISION_H
#define SALARIO_COMISION_H
class Salario_Comision: public Salario{

public:
        Salario_Comision(int,int);
        virtual ~Salario_Comision();
        int calcularSalarioTotal();

    protected:
        int comision;

};
#endif // SALARIO_COMISION_H
