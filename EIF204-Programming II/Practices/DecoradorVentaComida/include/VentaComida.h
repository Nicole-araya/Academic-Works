#ifndef VENTACOMIDA_H
#define VENTACOMIDA_H
#include <iostream>
#include <sstream>

using namespace std;

class VentaComida
{
    public:
        VentaComida();
        virtual ~VentaComida();
       virtual string  descripcion()=0;
       virtual double precio()=0;
       virtual string toStringIVA();
       virtual string toStringSINIVA();


    protected:

    private:
};

#endif // VENTACOMIDA_H
