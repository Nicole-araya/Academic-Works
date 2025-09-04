#ifndef REGION_H
#define REGION_H
#include <sstream>
#include <iostream>
using namespace std;
class Region
{
  protected:
        double presupuesto;
        int cantidadDeActividades;
 public:
    Region(double = 0, int = 0);
    virtual ~Region();
    virtual double getPresupuesto() = 0;
    virtual int getCantActivds() = 0;
    virtual string toString() = 0;
    virtual void agregarRegion(Region*) = 0;
};

#endif // REGION_H
