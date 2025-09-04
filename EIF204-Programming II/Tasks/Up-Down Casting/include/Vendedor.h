#ifndef VENDEDOR_H
#define VENDEDOR_H
#include"Empleado.h"
#include "Salario.h"

class Vendedor: public Empleado, Salario_Comision
{
    public:
        Vendedor(string,string,int,int,char);
        virtual ~Vendedor();
        void setCategoria(char);
        int getCategoria();
        string toString();


    protected:
       char categoria;  //Calificacion segun su desempeño


};

#endif // VENDEDOR_H
