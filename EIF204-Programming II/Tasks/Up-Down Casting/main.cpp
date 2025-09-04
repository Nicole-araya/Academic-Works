 //   PROGRA II
// Esteban Mojica Gonzalez
// Nicole Araya Ballestero

#include <iostream>
#include "AdmEmpleado.h"
#include "Empleado.h"
#include "Vendedor.h"
#include"Gerente.h"
#include"Cajero.h"

using namespace std;

int main()
{
    AdmEmpleado* a;

    cout << "-------UPCASTING-----------" << endl;

    Empleado* emp = new Cajero("Jose","111",12300,3);

    Gerente* g=new Gerente("Maria","222",25000,"recursos humanos");
    Vendedor* v = new Vendedor("Ana","555",23000,42000,'A');


        cout << emp->toString();

        a->mostrarInfo(g);
        a->mostrarInfo(v);

        cout  <<endl<< endl;

        cout << "-----DOWNCASTING------" << endl;

        Cajero* c= (Cajero*)(emp);

        Empleado* emp2 = g;
        Gerente* g2= (Gerente*)(emp2);

        cout << c->toString()<<endl;
        cout << g2->toString();

        cout  << endl<< endl;

        cout << "-----DYNAMIC-CASTING----" << endl;

        Empleado* emp3= g;
        Empleado* emp4= v;

        a->mostrarInfoDC(emp3);
        a->mostrarInfoDC(emp4);



    return 0;
}
