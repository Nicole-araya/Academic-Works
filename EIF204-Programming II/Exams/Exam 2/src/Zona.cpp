#include "Zona.h"

Zona::Zona(Coordinador* c, string n)
{
   encargado=c;
   nombreZona=n;
}

Zona::~Zona()
{
    //dtor
}

      //  Zona::Zona(const Zona&){}

       // Zona::Zona& operator = (const Zona&){}

 double Zona::getPresupuesto() {

     double suma;
for (int i = 0; i < vec.size(); i++){

  suma+=vec[i]->getPresupuesto();
}
return suma;
 }

 int Zona::getCantActivds() {
          double suma;
for (int i = 0; i < vec.size(); i++){

  suma+=vec[i]->getCantActivds();
}
return suma;
 }


 string Zona::toString() {
 stringstream s;
 s<<"----------------"<<endl;
 s<<">>>"<<nombreZona<<endl;
 s<<encargado->toString();
 s<<"----------------"<<endl;
for (int i = 0; i < vec.size(); i++){

   s<<vec[i]->toString();
}
 return s.str();
 }

 void Zona::agregarRegion(Region* r) {

 vec.push_back(r);

 }
