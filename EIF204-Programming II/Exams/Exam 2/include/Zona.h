#ifndef ZONA_H
#define ZONA_H
#include <vector>
#include "Region.h"
#include "Coordinador.h"

class Zona: public Region
{
private:
    Coordinador* encargado; // Persona encargada del grupo.
    string nombreZona;

    vector<Region*> vec;

 public:
        Zona(Coordinador* = NULL, string = "");
      //  Zona(const Zona&);
        virtual ~Zona();
      //  Zona& operator = (const Zona&);

         virtual double getPresupuesto() ;
    virtual int getCantActivds() ;
    virtual string toString() ;
    virtual void agregarRegion(Region*) ;

        // set�s
        // get�s
        // otros m�todos ...
};

#endif // ZONA_H
