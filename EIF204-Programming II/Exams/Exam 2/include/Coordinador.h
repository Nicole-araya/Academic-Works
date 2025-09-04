#ifndef COORDINADOR_H
#define COORDINADOR_H
#include <iostream>
#include <sstream>
using namespace std;
class Coordinador
{
    public:
        Coordinador(string,string,int);
        virtual ~Coordinador();
        string getNom();
        string getID();
        int getEdad();
        string toString();

    protected:

    private:
        string nomC;
        string id;
        int edad;

};

#endif // COORDINADOR_H
