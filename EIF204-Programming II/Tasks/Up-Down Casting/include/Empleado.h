#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>

using namespace std;
class Empleado
{
    public:

        Empleado(string,string);
        virtual~Empleado();
        void setNombre(string);
        void setID(string);

        string getNombre();
        string getID();
        string toString();


    protected:

    string nombre;
    string id;



};

#endif // EMPLEADO_H
