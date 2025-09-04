#include "Instituto.h"

Instituto::Instituto(string no,string nomR,int c):OrganoEducativo(no)
{
    nomRector=nomR;
    carerraDisp=c;
}

Instituto::~Instituto()
{
    //dtor
}

string Instituto::toString(){
stringstream s;

s   <<nombre <<'\n'
    <<nomRector <<'\n'
    <<carerraDisp <<'\n';



return s.str();
}
