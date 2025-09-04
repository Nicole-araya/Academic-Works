#include <iostream>
#include "Federaciones.h"
#include "Equipo.h"
#include <vector>
using namespace std;



int main()
{

Federaciones* f [6];

    for (int i = 0; i < 6; i++){
        f[i]=new Federaciones();
    }


    f[0]->add(new Equipo("Costa Rica","Rojo,azul,blanco","Concacaf"));
    f[0]->add(new Equipo("MEXICO","Verde","Concacaf"));
    f[1]->add(new Equipo("Japon","blanco rojo","Asia"));
    f[2]->add(new Equipo("Espana","amarrillo","UEFA"));


for (int i = 0; i < 3; i++)
{
cout<<(f[i])->toString();
cout <<"-------------------------------"<< endl;
}


    return 0;
}
