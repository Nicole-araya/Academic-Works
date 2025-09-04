#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <sstream>
using namespace std;
class Producto
{
public:
    Producto(string, int, int);
    virtual ~Producto();
    void setCan(int);
    int getCan();
    string toString();
    int getPrecio();
    int disponible();

protected:
    string nombre;
    int can;
    int precio;



};

#endif // PRODUCTO_H
