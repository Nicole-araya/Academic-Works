#include <iostream>
#include "OrganoEducativo.h"
#include "Preescolares.h"
#include "Escuela.h"
#include "Colegios.h"
#include "Instituto.h"

using namespace std;

int main()
{

OrganoEducativo *o=new Preescolares("111","111","111","111");

cout<< o->toString()<<endl;

o=new Escuela("222","222","222","222",2,2);

cout<< o->toString()<<endl;

o=new Colegios("333","333","333","333",3,"333");
cout<< o->toString()<<endl;


o=new Instituto("444","444",4);
cout<< o->toString()<<endl;

delete o;


    return 0;
}
