#ifndef GRUPO_H
#define GRUPO_H
#include "Region.h"
#include "Servicio.h"
class Grupo: public Region
{
    private:
        string codigoG; // Código del grupo.
        string nombreZ; // Nombre de la Zona al que pertenece.
        int categoria; // Categoría del grupo con base en la tabla.


 public:
        Grupo(string = "", string = "", int = 0,double =0,int=0);
       // Grupo(const Grupo&);
        virtual ~Grupo();
      //  Grupo& operator = (const Grupo&);


        virtual string getCod();
        virtual string getNom();
        virtual int getCateg();
        virtual double getPresupuesto();
        virtual int getCantActivds();


        virtual string toString() ;
        virtual void agregarRegion(Region*);

// Accesores.. get’s
// Mutadores... set’s
// otros Accesores ...

};

#endif // GRUPO_H
