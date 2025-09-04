#ifndef INSTITUTO_H
#define INSTITUTO_H
#include "OrganoEducativo.h"

class Instituto:public OrganoEducativo
{
    public:
        Instituto(string,string,int);
        virtual ~Instituto();
        string toString();

    protected:

        string nomRector;
        int carerraDisp;


};

#endif // INSTITUTO_H
