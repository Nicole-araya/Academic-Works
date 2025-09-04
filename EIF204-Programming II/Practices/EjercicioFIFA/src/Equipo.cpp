#include "Equipo.h"

Equipo::Equipo(string n,string cu,string s)
{
   nombre=n;
   colorUniforme=cu;
   siglas=s;
}

Equipo::~Equipo()
{
    //dtor
}

string Equipo::toString(){
stringstream s;

s <<nombre<<", "<<colorUniforme<<", "<<siglas<<endl;

return s.str();
}
