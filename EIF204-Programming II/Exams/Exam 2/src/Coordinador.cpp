#include "Coordinador.h"

Coordinador::Coordinador(string n,string i,int e)
{
   nomC=n;
   id=i;
   edad=e;
}

Coordinador::~Coordinador()
{
    //dtor
}


        string Coordinador::getNom(){return nomC;}
        string Coordinador::getID(){return id;}
        int Coordinador::getEdad(){return edad;}

         string  Coordinador::toString(){

         stringstream s;
         s<<id<<", "<<nomC<<", "<<edad<<endl;
         return s.str();
         }
