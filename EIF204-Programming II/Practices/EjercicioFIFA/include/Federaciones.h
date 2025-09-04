#ifndef FEDERACIONES_H
#define FEDERACIONES_H
#include "FIFA.h"
#include <vector>

class Federaciones:public FIFA
{
    public:
        Federaciones();
        virtual ~Federaciones();
        void add(FIFA*);
        string toString();

    protected:

    private:
        vector <FIFA*> federacion;
};

#endif // FEDERACIONES_H
