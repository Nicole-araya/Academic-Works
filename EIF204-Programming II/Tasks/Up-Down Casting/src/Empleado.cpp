#include "Empleado.h"

Empleado::Empleado(string n,string i)
{
   nombre=n;
   id=i;

}

Empleado::~Empleado()
{
    //dtor
}
 void Empleado::setNombre(string n){ nombre=n;}
        void Empleado::setID(string i){id=i;}
        string Empleado::getNombre(){return nombre;}
        string Empleado::getID(){return id;}


        string Empleado::toString(){
        stringstream s;

        s<<nombre<<" "<<id<<endl;

        return s.str();

        }
