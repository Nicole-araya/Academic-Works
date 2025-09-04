#include "AdmEmpleado.h"

AdmEmpleado::AdmEmpleado()
{
    //ctor
}

AdmEmpleado::~AdmEmpleado()
{
    //dtor
}

void AdmEmpleado::mostrarInfo(Empleado* e){

cout<<e->toString();


}

 void AdmEmpleado::mostrarInfoDC(Empleado* emp){

    Vendedor* v = dynamic_cast<Vendedor*>(emp);
    Gerente* g = dynamic_cast<Gerente*>(emp);
    Cajero* c = dynamic_cast<Cajero*>(emp);

        if (v)
        cout << v->toString() << endl;
    else if (g)
        cout << g->toString() << endl;
    else if (c)
        cout << c->toString() << endl;
    else
     cout << emp->toString() << endl;

        }
