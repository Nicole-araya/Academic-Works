#include "Colegios.h"

Colegios::Colegios(string no,string num,string dir,string nomD,int a,string t):OrganoEducativo(no)
{
     numero=num;
   direccion=dir;
   nomDirecto=nomD;
   annio=a;
   titulo=t;
}

Colegios::~Colegios()
{
    //dtor
}

string Colegios::toString(){
stringstream s;

s   <<nombre <<'\n'
    <<numero <<'\n'
    <<nomDirecto <<'\n'
    <<direccion <<'\n'
    <<annio <<'\n'
    <<titulo <<'\n';


return s.str();
}
