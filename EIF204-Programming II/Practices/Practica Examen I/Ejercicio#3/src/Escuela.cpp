#include "Escuela.h"

Escuela::Escuela(string no,string num,string dir,string nomD,int a,int c): OrganoEducativo(no)
{
    numero=num;
   direccion=dir;
   nomDirecto=nomD;
   annio=a;
   cantidad=c;
}

Escuela::~Escuela()
{
    //dtor
}

string Escuela::toString(){
stringstream s;

s   <<nombre <<'\n'
    <<numero <<'\n'
    <<nomDirecto <<'\n'
    <<direccion <<'\n'
    <<annio <<'\n'
    <<cantidad <<'\n';


return s.str();
}
