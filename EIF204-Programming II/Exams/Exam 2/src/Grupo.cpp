#include "Grupo.h"

Grupo::Grupo(string cod, string nom, int cate,double pre,int can ):Region(pre, can)
{
    codigoG=cod;
    nombreZ=nom;
    categoria=cate;

}

Grupo::~Grupo()
{
    //dtor
}

//Grupo::Grupo(const Grupo&){}

 //Grupo& operator = (const Grupo&);

 string Grupo::getCod(){return codigoG;}
  string Grupo::getNom(){return nombreZ;}
  int Grupo::getCateg(){return categoria;}

 double Grupo::getPresupuesto(){

 presupuesto=Servicio::getPresupuesto(categoria);
 return presupuesto;
 }

 int Grupo::getCantActivds(){

 cantidadDeActividades=Servicio::getActivPorAnio(categoria);
 return cantidadDeActividades;
 }

 string Grupo::toString() {
 stringstream s;

s<<"Grupo: "<<endl;
s<<codigoG<<", "<<nombreZ<<",Grupo: "<< categoria<<endl;
s<< "Presupuesto "<<getPresupuesto();
s<<", Activudades "<<getCantActivds()<<endl;
 return s.str();
 }

void Grupo::agregarRegion(Region* r){}
