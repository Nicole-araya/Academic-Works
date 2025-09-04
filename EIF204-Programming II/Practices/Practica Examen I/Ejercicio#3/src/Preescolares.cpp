#include "Preescolares.h"

Preescolares::Preescolares(string nom,string nu,string dir,string nomD):OrganoEducativo(nom)
{
   numero=nu;
   direccion=dir;
   nomDirector=nomD;
}

Preescolares::~Preescolares()
{
    //dtor
}

string Preescolares::toString(){
stringstream s;

s   <<nombre <<'\n'
    <<numero <<'\n'
    <<nomDirector <<'\n'
    <<direccion <<'\n';


return s.str();
}
