#ifndef ORGANOEDUCATIVO_H
#define ORGANOEDUCATIVO_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class OrganoEducativo
{
    public:
        OrganoEducativo(string);
        virtual ~OrganoEducativo();
        virtual string toString()=0;

    protected:
        string nombre;

};

#endif // ORGANOEDUCATIVO_H
